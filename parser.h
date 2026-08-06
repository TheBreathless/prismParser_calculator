#ifndef PARSER_H
#define PARSER_H

#include <QString>

#include <stack>
#include <variant>


class Parser
{
public:
    Parser();

    enum class LexerTokens {
        UNKNOWN = -10,
        SPACE = -5,
        NUMBER = 0,
        SIGN_ADD, SIGN_SUB,
        SIGN_MUL, SIGN_DIV, SIGN_MOD,
        E_NOT,
        POW, SQRT, ROOT,
        BRACKET_L, BRACKET_R
    };

    enum class ParserTokens {
        INVALID = -100,
        E_NOT = 0,
        ADD = 1, SUB,
        MUL, DIV, MOD,
        POW, SQRT, ROOT,
        UNARY_PLUS, UNARY_MIN,
        L_BRACKET, R_BRACKET
    };

    struct lexerData{
        LexerTokens lexerTokens;
        std::variant<std::monostate, long double> value;
    };

    long double mainParser(QString string);

private:
    bool divByZero = false;
    bool isValid = true;

    std::vector<lexerData> lexerTokenList;
    std::vector<ParserTokens> parserTokenList;

    std::vector<lexerData>mainLexer(QString expression);
    ParserTokens convertTokens(const Parser::LexerTokens& pt, bool& expt_unary);

    int getPriority(const Parser::ParserTokens& lt);
    void evaluateStack(std::stack<long double>& nums, std::stack<Parser::ParserTokens>& sign);
};

#endif // PARSER_H