#include "scientificEngine.h"
//#include "math.cpp"     //<--

ScientificEngine::ScientificEngine() {}


void ScientificEngine::handleResultStream(QString& opString, short int& mismatchedP)
{
    if(opString.isEmpty())
        return;

    for(int i = 0; i < mismatchedP; mismatchedP--)   //Adds as many mismatched parentesys as necessary
        opString.append(")");

    this->highResResult = parseString(opString);

    if(this->divByZero)
    {
        opString.assign("DIVISION BY 0");
        this->divByZero = false;
    }
    else if(!this->isValid)
    {
        opString.assign("SYNTAX ERROR");
        this->isValid = true;
    }
    else if(std::isinf(highResResult))
        opString.assign("MATH OVERFLOW");
    else
        opString.setNum((double)highResResult);
        //opString.assign(std::to_string(highResResult));
}

long double ScientificEngine::parseString(QString originalString)
{
    std::stack<long double> nums;
    std::stack<char> sign;

    this->isValid = translateString(originalString);

    std::string stdString = originalString.toStdString();
    std::string numBuffer;

    short int notMatchingP = 0;

    if(!this->isValid)
        return 0;

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
        }
        else if(c == ')')
        {
            notMatchingP--;

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

bool ScientificEngine::translateString(QString& string)
{
    for(int i = 0; i < string.length(); i++)
    {
        if(string.at(i) == "e")     //If statement necessary since switch doesnt accept QStrings and QChars and their toLatin1 conversions cause data loss for >1 byte chars
        {
            if(i + 1 < string.length())
            {
                if(string.at(i+1) == '+')
                {
                    string.replace(i, 2, "*10^");
                }
                else if(string.at(i+1).isDigit())
                {
                    string.replace(i, 1, "*10^");
                }
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
        else if(string.at(i) == "÷")
            string.replace(i, 1, '/');
        //else if(!std::isdigit(string.at(i).toLatin1()) && !this->isSign(string.at(i).toLatin1()))     //Bugged for powers
        //    return false;
    }


    //string.replace("²√(", "(");
    //string.replace(")", ")^(1/2)");

    return true;
}

bool ScientificEngine::isSign(char c)
{
    std::string validSigns = "+-*/%^()se";

    return validSigns.find(c) != std::string::npos;
}

void ScientificEngine::topAndPop(std::stack<long double>& nums, std::stack<char>& sign)
{
    long double a = nums.top();
    nums.pop();

    long double b = nums.top();
    nums.pop();

    nums.push(evaluateStep(a, b, sign.top()));
    sign.pop();
}

short int ScientificEngine::getWeight(char c)
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

long double ScientificEngine::evaluateStep(long double a, long double b, char sign)
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