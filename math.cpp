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
        this->scientificCalculation(value);
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
        if(!operationString.isEmpty())
        {
            if(this->operationString.endsWith("."))
                this->isDecimal = false;

            this->operationString.removeLast();

            if(!operationString.isEmpty())
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
    this->sign.resize(1);   //I dont clear sign because the first element has to be a + (see comment in math.h, at sign definition

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
        case '+': case '-': case '*': case '/': case '%': //case '^':   //^ for future updates

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
void Math::scientificCalculation(char value)
{
    if(std::isdigit(value) || value == '(' || value == ')')
    {
        operationString.append(value);

        this->newValue = false; //A sign can be added to the string, since now there would be a number behind it

        if(value == '(')    //Small check to prevent mismatched parentesys. The final check happens at the = press
            this->mismatchedP++;
        else if(value == ')')
            this->mismatchedP--;
    }
    else if(value == '.')
    {
        if(!this->isDecimal)
            operationString.append('.');

        isDecimal = true;
    }
    else if(!isSign(value))
    {
        switch(value)
        {
        case 'P':
            this->operationString.append("π");
            break;
        case 'r':
            this->operationString.append("²√(");
            break;
        case 'R':
            this->operationString.clear();
            this->operationString.append("INVALID REQUEST");
            break;
        case 'C':
            clearLast();
            break;

        case 'D':
            clearAll();
            break;

        case 'N':
            msgHelp1();
            break;

        case '=':
            for(int i = 0; i < this->mismatchedP; mismatchedP--)   //Adds as many mismatched parentesys as necessary
                operationString.append(")");

            this->result = parseString(this->operationString);

            if(this->operationString.contains("18*59") || this->operationString.contains("1062/0") || this->operationString.contains("1062÷0"))
                showEasterEgg1();

            if(this->divByZero)
            {
                this->operationString.assign("DIVISION BY 0");
                this->divByZero = false;
            }
            else if(!this->isValid)
            {
                this->operationString.assign("SYNTAX ERROR");
                this->isValid = true;
            }
            else if(std::isinf(result))
                this->operationString.assign("MATH OVERFLOW");
            else
                this->operationString.setNum(result);

            emit contentUpdated(this->operationString, this->scientific);

            break;
        }
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
            case 's':
                if(!this->operationString.isEmpty())
                    this->operationString.append("^2");
                break;
            default:
                qDebug() << "The char is a sign, but it's not handled";
            }

            newValue = true;
            isDecimal = false;
        }
    }
}

bool Math::translateString(QString& string)
{
    for(int i = 0; i < string.length(); i++)
    {
        if(string.at(i) == "e")     //If statement necessary since switch doesnt accept QStrings and QChars and their toLatin1 conversions cause data loss for >1 byte chars
        {
            if(i + 1 < string.length() && string.at(i+1) == '+')
            {
                //Example 5e+15 -> 5*10^15
                string.replace(i + 1, 1, "10^");
                string.replace(i, 1, '*');
            }
            else
                return false;   //The e is not written correctly
        }
        else if(string.at(i) == "π")
        {
            if(string.length() > 10)
                string.replace(i, 1, DEFAULT_PI);   //PI default macro (high precision avaiable)
            else
                string.replace(i, 1, HIGH_PRES_PI);

            if(i > 0 && std::isdigit(string.at(i - 1).toLatin1()))
                string.insert(i, '*');
        }
        /*
        else if(string.at(i) == "²")
        {
            string.replace(i, 2, "^");
        }
        */
        else if(string.at(i) == "÷")
            string.replace(i, 1, '/');
    }

    string.replace("²√(", "(");
    string.replace(")", ")^(1/2)");

    return true;
}



long double Math::parseString(QString originalString)
{
    std::stack<long double> nums;
    std::stack<char> sign;

    this->isValid = translateString(originalString);

    std::string stdString = originalString.toStdString();
    std::string numBuffer;

    short int notMatchingP = 0;
    short int openedP = 0;
    short int closedP = 0;

    for(char c: stdString)
    {
        if(std::isdigit(c) || c == '.')
            numBuffer += c;
        else if(std::isspace(c))
            continue;
        else if(c == '(')
        {
            sign.push(c);
            notMatchingP++;
            openedP++;
        }
        else if(c == ')')
        {
            notMatchingP--;
            closedP++;

            if(!numBuffer.empty())
            {
                nums.push(std::stold(numBuffer));
                numBuffer.clear();
            }

            while(!sign.empty() && sign.top() != '(')
                topAndPop(nums, sign);

            sign.pop();
        }
        else
        {
            if(!numBuffer.empty())
            {
                nums.push(std::stold(numBuffer));
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
        nums.push(std::stold(numBuffer));

    if(notMatchingP == 0)
        while(!sign.empty())
            topAndPop(nums, sign);
    else
        this->isValid = false;

    return nums.top();
}

bool Math::isSign(char c)
{
    std::string validSigns = "+-*/%^()s";

    return validSigns.find(c) != std::string::npos;
}

void Math::topAndPop(std::stack<long double>& nums, std::stack<char>& sign)
{
    long double a = nums.top();
    nums.pop();

    long double b = nums.top();
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
        return -200;    //Anything lower than 1 is enough
        break;
    default:
        return 0;
    }

    std::terminate();
}

long double Math::evaluateStep(long double a, long double b, char sign)
{
    switch (sign)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return b - a;   //The stack extract numbers in inverted order
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

        return b / a;
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
    msg.setInformativeText("La pagina di aiuto sarà disponibile entro la versione v.1.3");

    msg.setIcon(QMessageBox::Warning);

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
    player->setParent(video);
    player->setSource(QUrl::fromLocalFile(".\\CalcGameReview.media"));

    video->setWindowTitle("Recensione gioco \"calcolatrice\"");
    video->setGeometry(30, 30, 640, 360);
    video->setAttribute(Qt::WA_DeleteOnClose);  //Delete object to prevent memory leak when window is closed

    audio->setVolume(1);
    audio->setParent(video);

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


void genericVideoPlay(QString url)
{
    QMediaPlayer *player = new QMediaPlayer();
    QVideoWidget *video = new QVideoWidget();
    QAudioOutput *audio = new QAudioOutput();
    QUrl fileUrl = QUrl::fromLocalFile(url);

    player->setVideoOutput(video);
    player->setAudioOutput(audio);
    player->setParent(video);

    if(fileUrl.isLocalFile() && QFileInfo::exists(fileUrl.toLocalFile()))
        player->setSource(fileUrl);
    else
    {
        video->setWindowTitle("Riproduzione video");
        video->setGeometry(30, 30, 640, 360);
        video->setAttribute(Qt::WA_DeleteOnClose);

        audio->setVolume(1);
        audio->setParent(video);

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
}