#include "parser.h"

#include <QDebug>

Parser::Parser() {}


long double Parser::mainParser(QString string)
{
    using LT = Parser::LexerTokens;
    using PT = Parser::ParserTokens;

    std::stack<long double> nums;
    std::stack<ParserTokens> signs;

    std::vector<lexerData> ltList = this->mainLexer(string);
    bool expect_unary = false;

    for(int i = 0; i < ltList.size(); i++)
    {
        if(isValid == false)
            return 0.0;

        LexerTokens lexerToken = ltList.at(i).lexerTokens;
        ParserTokens pt = convertTokens(lexerToken, expect_unary);

        if(lexerToken == LT::NUMBER)
        {
            nums.push(std::get<long double>(ltList.at(i).value));
            expect_unary = false;
        }
        else if(lexerToken == LT::BRACKET_L)
        {
            signs.push(pt);
            expect_unary = true;
        }
        else if(lexerToken == LT::BRACKET_R)
        {
            while(!signs.empty() && !nums.empty() && signs.top() != PT::L_BRACKET)
                evaluateStack(nums, signs);

            if(signs.empty())
            {
                //qDebug() << "Invalid because signs are empty";
                isValid = false;
            }
            else
                signs.pop();

            expect_unary = false;
        }
        else
        {
            while(!signs.empty() && !nums.empty() && getPriority(pt) <= getPriority(signs.top()))
            {
                evaluateStack(nums, signs);
                continue;
            }

            signs.push(pt);

            expect_unary = true;
        }
    }

    while(!signs.empty() && !nums.empty())
        evaluateStack(nums, signs);


    if(!nums.empty())
        return nums.top();
    else isValid = false;


    return 0.0;
}


std::vector<Parser::lexerData>Parser::mainLexer(QString expression)
{
    using LT = Parser::LexerTokens;

    std::vector<Parser::lexerData> ltList;
    short int i = 0;
    bool skipNextSign = false;

    std::string numBuffer;

    while(i < expression.length())
    {
        if(std::isspace(expression.at(i).unicode()))
            i++;
        else if(std::isdigit(expression.at(i).unicode()))
        {
            numBuffer += expression.at(i).unicode();
            i++;

            if(skipNextSign)
                skipNextSign = false;
        }
        else
        {
            if(!numBuffer.empty())
            {
                ltList.push_back({LT::NUMBER, std::stold(numBuffer)});
                numBuffer.clear();
            }
            if(skipNextSign)
                skipNextSign = false;
            else
                switch(expression.at(i).unicode())
                {
                case '+':
                    ltList.push_back({LT::SIGN_ADD});
                    break;
                case '-':
                    ltList.push_back({LT::SIGN_SUB});
                    break;
                case '*':
                    ltList.push_back({LT::SIGN_MUL});
                    break;
                case '/':
                    ltList.push_back({LT::SIGN_DIV});
                    break;
                case '%':
                    ltList.push_back({LT::SIGN_MOD});
                    break;
                case 'e':
                    ltList.push_back({LT::E_NOT});
                    skipNextSign = true;
                    break;
                case '^':
                    ltList.push_back({LT::POW});
                    break;
                case '(':
                    ltList.push_back({LT::BRACKET_L});
                    break;
                case ')':
                    ltList.push_back({LT::BRACKET_R});
                    break;
                case 'P':
                    ltList.push_back({LT::NUMBER, M_PI});
                    break;
                case 'r':
                    ltList.push_back({LT::SQRT});
                    break;
                case 'R':
                    ltList.push_back({LT::ROOT});
                    break;
                default:
                    ltList.push_back({LT::UNKNOWN});
                }

            i++;
        }
    }

    if(!numBuffer.empty())
        ltList.push_back({LT::NUMBER, std::stold(numBuffer)});

    return ltList;
}


int Parser::getPriority(const Parser::ParserTokens& pt)
{
    using LT = Parser::LexerTokens;
    using PT = Parser::ParserTokens;

    switch(pt)
    {
    case PT::ADD: case PT::SUB:
        return 1;
        break;

    case PT::MUL: case PT::DIV: case PT::MOD:
        return 3;
        break;

    case PT::POW: case PT::ROOT: case PT::SQRT:
        qDebug() << "Ottenuta priorita'";
        return 5;
        break;

    case PT::UNARY_PLUS: case PT::UNARY_MIN:
        return 10;
        break;

    case PT::E_NOT:
        return 15;
        break;

    case PT::L_BRACKET:
        return -50;
        break;

    case PT::R_BRACKET:
        return 50;

    case PT::INVALID:
        return 0;
        break;
    }

    qDebug() << "invalid getpriority";
    isValid = false;
    return 0;
}

Parser::ParserTokens Parser::convertTokens(const Parser::LexerTokens& pt, bool& expt_unary)
{
    using LT = Parser::LexerTokens;
    using PT = Parser::ParserTokens;

    switch(pt)
    {
    case LT::SIGN_ADD:
        if(!expt_unary)
            return PT::ADD;
        else
            expt_unary = false;
        return PT::UNARY_PLUS;
        break;

    case LT::SIGN_SUB:
        if(!expt_unary)
            return PT::SUB;
        else
            expt_unary = false;
        return PT::UNARY_MIN;
        break;
    default:
        break;
    }

    if(!expt_unary)
        expt_unary = true;
    else
        expt_unary = false;        //Could have logic issues

    switch(pt)
    {
    case LT::E_NOT:
        return PT::E_NOT;
        break;

    case LT::SIGN_MUL:
        return PT::MUL;
        break;

    case LT::SIGN_DIV:
        return PT::DIV;
        break;

    case LT::SIGN_MOD:
        return PT::MOD;
        break;

    case LT::POW:
        return PT::POW;
        break;

    case LT::SQRT:
        qDebug() << "SQRT convertito";
        return PT::SQRT;
        break;

    case LT::ROOT:
        return PT::ROOT;
        break;

    case LT::BRACKET_R:
        return PT::R_BRACKET;
        break;

    case LT::BRACKET_L:
        return PT::L_BRACKET;
        break;

    default:
        qDebug() << "Il segno" << (int)pt << "non e' valido";
        return PT::INVALID;
    }

}

void Parser::evaluateStack(std::stack<long double>& nums, std::stack<Parser::ParserTokens>& sign)
{
    using PT = Parser::ParserTokens;

    long double a = nums.top();
    nums.pop();

    if(!nums.empty())
    {
        long double b = nums.top();
        nums.pop();

        qDebug() << "Operation: " << (double)b << (int)sign.top() << (double)a;

        switch(sign.top())
        {
        case PT::ADD:
            nums.push(b + a);
            break;

        case PT::SUB:
            nums.push(b - a);
            break;

        case PT::MUL:
            nums.push(b * a);
            break;

        case PT::DIV:
            if(a != 0)
                nums.push((int)b / (int)a);
            else
                divByZero = true;
            break;

        case PT::MOD:
            if(a != 0)
                nums.push((int)b % (int)a);
            else
                divByZero = true;
            break;

        case PT::E_NOT:
            nums.push(b*std::pow(10, a));
            break;

        case PT::POW:
            nums.push(std::pow(b, a));
            break;

        case PT::ROOT:
            std::pow(b, 1/a);
            break;

        default:
            break;
        }
    }

    qDebug() << "Non sono morto";
    qDebug() << "Segno:" << (int)sign.top();

    switch(sign.top())
    {
    case PT::SQRT:
        qDebug() << "Operation: " << (int)sign.top() << (double)a;
        nums.push(std::sqrt(a));
        break;

    case PT::UNARY_PLUS:
        nums.push(a);
        break;

    case PT::UNARY_MIN:
        nums.push(a*(-1));
        break;
    default:
        break;
    }

    sign.pop();
}