#include "math.h"

Math::Math(QObject *parent): QObject(parent)    //Costruttore classe Math
{

}

void Math::on_pushButton_released(char value)
{
    if(!this->scientific)
    {
        this->registerCalculation(value);
        emit contentUpdated(this->displayed, this->scientific);
    }
    else
    {
        this->stringCalculation(value);
        emit contentUpdated(this->operationString, this->scientific);
    }
}

void Math::specialToggled()
{

    if(!this->scientific)
        this->scientific = true;
    else
        this->scientific = false;

    emit scientificToggled(this->scientific);
}

void Math::clearLast()
{
    if(!scientific)
    {
        if(this->displayed.endsWith("."))
            this->isDecimal = false;

        this->displayed.removeLast();
    }
    else
    {
        if(this->operationString.endsWith("."))
            this->isDecimal = false;

        this->operationString.removeLast();

        switch(this->operationString.back().toLatin1())
        {
        case '+': case '-': case '*': case '/': case '%':
            this->newValue = true;
            break;
        default:
            this->newValue = false;
        }
    }
}

void Math::clearAll()
{
    this->displayed.clear();
    this->registers.clear();
    this->sign.resize(1);
    this->result = 0;

    this->isDecimal = false;
    this->newValue = false;

    this->operationString.clear();
}

///Standard calculator
void Math::testCalculateResult()
{
    if(this->sign.at(0) != '+' || this->sign.at(0) != '-')
        this->sign.at(0) = '+';

    this->result = 0;

    for(int i = 0; i < this->registers.size(); i++)
    {

        switch(this->sign[i])
        {
        case '+':
            result += this->registers[i];
            break;

        case '-':
            result -= this->registers[i];
            break;

        case '*':
            result *= this->registers[i];
            break;

        case '/':
            result /= this->registers[i];
            break;

        case '%':
            result = (int)result % (int)this->registers[i];
            break;

        case '^':
            qCritical() << "Function still not implemented";

            break;

        default:
            std::terminate();
        }
    }

    this->registers.clear();
    this->sign.resize(1);

    this->displayed.setNum(result);

    emit contentUpdated(this->displayed, this->scientific);
}

void Math::registerCalculation(char value)
{
    if(value >= 48 && value <= 57)
    {
        if(newValue)
        {
            this->displayed.clear();

            emit contentUpdated(this->displayed, this->scientific);

            newValue = false;
        }

        this->displayed.append(value);
    }
    else
    {
        switch(value)
        {
        case '+': case '-': case '*': case '/': case '%': //case '^':

            if(this->displayed.isEmpty())
            {
                if((this->registers.empty() && value == '+' || value == '-') && this->sign.size() == 1)
                    this->sign.at(0) = value;
                else
                    this->sign.at(0) = '+';
            }
            else
            {
                if(!newValue)
                {
                    this->sign.push_back(value);

                    bool flag = false;
                    this->registers.push_back(this->displayed.toDouble(&flag));

                    if(!flag)
                        std::terminate();
                }
                else
                    this->sign.back() = value;

                this->newValue = true;
            }

            break;

        case '=':
            if(newValue == false)   //Added if statement to fix calculation error with last register
                this->registers.push_back(this->displayed.toDouble());

            testCalculateResult();
            break;

        case 'C':   //Single delete
            clearLast();

            break;
        case 'D':   //Delete all
            clearAll();

            break;

        case '.':

            if(!isDecimal)
                this->displayed.append(".");

            isDecimal = true;
            break;

        case 'N':
            this->msgCatanzaro();

            break;

        case '^':
            this->msgSubscription();
            break;

        default:
            qDebug() << "Errore: opzione non implementata";

        }
    }
}

///Scientific calculator
void Math::stringCalculation(char value)
{
    if(std::isdigit(value) || value == '(' || value == ')')
    {
        operationString.append(value);

        this->newValue = false;
    }
    else if(value == '.')
    {
        if(!this->isDecimal)
            operationString.append('.');

        isDecimal = true;
    }
    else if(isSign(value))
    {
        if(!newValue)
        {
            switch(value)
            {
            case '+': case '-':
                if(!this->operationString.isEmpty())    //The parser is not ready yet for signed numbers (ex. -5 or +3, but allows 0-5 or just 3)
                    this->operationString.append(value);
                break;
            case '*': case '/': case '%': case '^':
                if(!this->operationString.isEmpty())
                    this->operationString.append(value);
                break;
            }

            newValue = true;
            isDecimal = false;
        }
    }
    else
    {
        switch(value)
        {
        case 'C':
            clearLast();
            break;

        case 'D':
            clearAll();
            break;

        case '=':
            this->result = solveString(this->operationString);

            if(this->operationString.contains("18*59") || this->operationString.contains("1062/0"))
                showEasterEgg1();

            if(this->divByZero)
            {
                this->operationString.assign("MATH ERROR: DIV BY 0");
                this->divByZero = false;
            }
            else if(!this->isValid)
            {
                this->operationString.assign("SYNTAX ERROR");
                this->isValid = true;
            }
            else
                this->operationString.setNum(result);

            emit contentUpdated(this->operationString, this->scientific);

            break;
        }
    }
}

double Math::solveString(QString originalString)
{
    std::stack<double> nums;
    std::stack<char> sign;
    std::string stdString = originalString.toStdString();
    std::string numBuffer;

    for(char c: stdString)
    {
        if(std::isdigit(c))
            numBuffer += c;
        else if(std::isspace(c))
            continue;
        else
        {
            if(!numBuffer.empty())
            {
                nums.push(std::stod(numBuffer));
                numBuffer.clear();
            }

            if(sign.empty())
                sign.push(c);
            else
            {
                while(!nums.empty() && !sign.empty() && getWeight(sign.top()) >= getWeight(c))
                    topAndPop(nums, sign);

                sign.push(c);
            }
        }
    }

    if(!numBuffer.empty())
        nums.push(std::stod(numBuffer));

    while(!sign.empty())
        topAndPop(nums, sign);

    return nums.top();
}

bool Math::isSign(char c)
{
    std::string validSigns = "+-*/%^()";

    return validSigns.find(c) != std::string::npos;
}

void Math::topAndPop(std::stack<double>& nums, std::stack<char>& sign)
{
    double a = nums.top();
    nums.pop();

    double b = nums.top();
    nums.pop();

    nums.push(evaluateStep(a, b, sign.top()));
    sign.pop();
}

short int Math::getWeight(char c)
{
    switch (c)
    {
    case '+': case '-':
        return 1;
        break;
    case '*': case '/': case '%':
        return 2;
        break;
    case '^':
        return 3;
        break;
    case '(': case ')':
        return 4;
        break;
    default:
        return 0;
    }

    std::terminate();
}

double Math::evaluateStep(double a, double b, char sign)
{
    switch (sign)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return b - a;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        if (a == 0)
        {
            this->divByZero = true;
            return 0;
        }

        return b / a;	//Possible fix
        break;
    case '%':
        return (int)b % (int)a;
        break;
    case '^':
        return std::pow(b, a);
        break;
    default:
        return 0;
    }
}



///Msg boxes
void Math::msgCatanzaro()
{
    QMessageBox niggaMsg(nullptr);   //Has some bugs

    niggaMsg.setWindowTitle("SOLUZIONE FINALE");
    niggaMsg.setText("La soluzione finale ha avuto inizio");
    niggaMsg.setInformativeText("Confermare l'annientamento del medio oriente?");
    niggaMsg.setIcon(QMessageBox::Warning);
    niggaMsg.setStandardButtons(QMessageBox::Yes | QMessageBox::Abort | QMessageBox::Cancel);
    niggaMsg.setDefaultButton(QMessageBox::Yes);

    niggaMsg.exec();
}

void Math::msgSubscription()
{
    QMessageBox msg(nullptr);

    msg.setWindowTitle("Funzionalità premium");

    msg.setText("Per questa funzionalità è necessario un abbonamento");
    msg.setInformativeText("4,99€ per il primo mese, poi 9,99€.\nIl pagamento è esclusivamente via bonifico bancario");

    msg.setIcon(QMessageBox::Question);

    msg.setStandardButtons(QMessageBox::Yes | QMessageBox::Ignore | QMessageBox::Cancel);
    msg.setDefaultButton(QMessageBox::Yes);

    int lvalue = msg.exec();

    switch(lvalue)
    {
    case QMessageBox::Yes:
        msg.setIcon(QMessageBox::Warning);
        msg.setText("In attesa della conferma...");
        msg.setInformativeText("In attesa dell'approvazione della transazione...");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
        break;

    default:
        msg.setIcon(QMessageBox::Warning);
        msg.setText("Transazione annullata");
        msg.setInformativeText("Annullamento della transazione...");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
        break;
    }
}

void Math::msgNotImplemented()
{
    QMessageBox msg(nullptr);

    msg.setWindowTitle("Funzionalità non implementata");

    msg.setText("La funzionalità richiesta non esiste o non è stata implementata");
    msg.setInformativeText("Aggiorna o riavvia l'app, altrimenti segnala il problema\nUn log contenente il report è stato generato");

    msg.setIcon(QMessageBox::Critical);

    msg.setDefaultButton(QMessageBox::Ok);

    std::fstream f("errorLog.txt", std::ios::in | std::ios::app);
    f << "Error: notImplemented was called\n";
    f.close();

    msg.exec();
}

void Math::msgHelp1()
{
    QMessageBox msg(nullptr);

    msg.setWindowTitle("Funzionalità non implementata");

    msg.setText("La funzionalità richiesta non esiste o non è stata implementata");
    msg.setInformativeText("Aggiorna o riavvia l'app, altrimenti segnala il problema\nUn log contenente il report è stato generato");

    msg.setIcon(QMessageBox::Critical);

    msg.setDefaultButton(QMessageBox::Ok);

    msg.exec();
}

///Easter eggs
void Math::showEasterEgg1()
{
    QMediaPlayer *player = new QMediaPlayer();
    QVideoWidget *video = new QVideoWidget();
    QAudioOutput *audio = new QAudioOutput();

    player->setVideoOutput(video);
    player->setAudioOutput(audio);
    player->setSource(QUrl::fromLocalFile(".\\CalcGameReview.media"));

    video->setWindowTitle("Recensione gioco \"calcolatrice\"");
    video->setGeometry(30, 30, 640, 360);
    video->setAttribute(Qt::WA_DeleteOnClose);

    audio->setVolume(0.8);

    player->play();
    video->show();

    QObject::connect(player, &QMediaPlayer::mediaStatusChanged, [video, player, audio](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::EndOfMedia) {
            video->close();
            player->deleteLater();
            video->deleteLater();
            audio->deleteLater();

        }
    });
}