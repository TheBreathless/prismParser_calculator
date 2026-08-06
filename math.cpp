#include "math.h"
#include "scientificEngine.h"
#include "mediaEngine.h"

Math::Math(QObject *parent): QObject(parent)    //Costruttore classe Math
{
    scientificEngine_ptr = new ScientificEngine();
    mediaEngine_ptr = new MediaEngine();
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
        this->operateScientificMode(value);
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
void Math::evaluateRegisters()
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
            if(this->registers[i] != 0)
                result /= this->registers[i];
            break;
        case '%':
            if(this->registers[i] != 0)
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

            evaluateRegisters();
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
            mediaEngine_ptr->genericHTMLBrowser(".\\Documentation\\index.html");
            break;

        case '^':
            break;

        default:
            qDebug() << "Errore: opzione non implementata";

        }
    }
}

///Scientific calculator
void Math::operateScientificMode(char value)
{
    if(std::isdigit(value) || value == '(' || value == ')')
    {
        operationString.append(value);

        this->newValue = false; //A sign can be added to the string, since now there would be a number behind it
        this->bufferedSign = 0;

        if(value == '(')        //Small check to prevent mismatched parentesys. The final check happens at the = press
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
    else if(!scientificEngine_ptr->isSign(value))
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
        case 'e':
            this->operationString.append('e');
            break;
        case 'C':
            clearLast();
            break;

        case 'D':
            clearAll();
            break;

        case 'N':
            mediaEngine_ptr->genericHTMLBrowser(".\\Documentation\\index.html");
            break;

        case '=':
            mediaEngine_ptr->checkForEasterEggs(this->operationString);

            scientificEngine_ptr->handleResultStream(this->operationString, this->mismatchedP);
            break;
        }
    }
    else if(scientificEngine_ptr->isSign(value))
    {
        switch(value)
        {
        case '+': case '-':
            if(this->bufferedSign < 2)
                this->operationString.append(value);
            break;
        case '*': case '/': case '%': case '^':
            if(!this->operationString.isEmpty() && this->bufferedSign < 1)
                this->operationString.append(value);
            else
                return;
            break;
        case 's':
            if(!this->operationString.isEmpty() && this->bufferedSign < 1)
                this->operationString.append("^2");
            else
                return;
            break;
        case 'e':
            if(!this->operationString.isEmpty() && this->bufferedSign < 1)
                this->operationString.append('e');
            else
                return;
            break;
        default:
            qDebug() << "The char is a sign, but it's not handled";
        }

        this->bufferedSign++;
        if(this->bufferedSign == 1)
            this->isDecimal = false;
    }
}