#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
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
        ADD = 1, SUB,
        MUL, DIV, MOD,
        POW, SQRT, ROOT,
        UNARY_PLUS, UNARY_MIN,
        E_NOT,
        L_BRACKET, R_BRACKET
    };

    struct lexerData{
        LexerTokens lexerTokens;
        std::variant<std::monostate, long double> value;
    };

    void handleCalculations(std::string& string, short int& mismatchedP);

private:
    double result = 0.0;

    bool divByZero = false;
    bool isValid = true;

    long double mainParser(std::string& string);
    std::vector<lexerData>mainLexer(std::string expression);

    std::vector<lexerData> lexerTokenList;
    std::vector<ParserTokens> parserTokenList;

    ParserTokens convertTokens(const Parser::LexerTokens& pt, bool& expt_unary);

    int getPriority(const Parser::ParserTokens& lt);
    void evaluateStack(std::stack<long double>& nums, std::stack<Parser::ParserTokens>& sign);
};

#endif // PARSER_H