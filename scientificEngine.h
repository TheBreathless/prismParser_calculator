#ifndef SCIENTIFICENGINE_H
#define SCIENTIFICENGINE_H

#include <QString>

#include <stack>

#define DEFAULT_PI "3.14159265"
#define HIGH_PRES_PI "3.141592653589793"

class ScientificEngine
{
public:
    explicit ScientificEngine();

    bool isSign(char c);
    void handleResultStream(QString& opString, short int& mismatchedP);

private:
    long double highResResult;

    bool divByZero = false; //Division by 0 flag
    bool isValid = true;    //Usata per le corrispondenze tra parentesi

    long double parseString(QString string);
    bool translateString(QString& string);

    short int getWeight(char c);

    void topAndPop(std::stack<long double>& nums, std::stack<char>& sign);   //Codice contenuto in un paio di cicli while, legge e cancella gli elementi dello stack
    long double evaluateStep(long double a, long double b, char sign);     //Calcola gli elementi passati per parametro, usato in combinazione con topAndPop(...)

};
#endif // SCIENTIFICENGINE_H