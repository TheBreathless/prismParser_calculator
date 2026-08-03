#ifndef SCIENTIFICENGINE_H
#define SCIENTIFICENGINE_H

#pragma once
#include <QString>

#include <stack>
#include <string>

#define DEFAULT_PI "3.14159265"
#define HIGH_PRES_PI "3.141592653589793"

class ScientificEngine
{
public:
    ScientificEngine();


    void handleResultStream(QString& opString);

private:
    long double parseString(QString string);
    bool translateString(QString& string);

    bool isSign(char c);            //Controlla se c fa parte di un gruppo arbitrario di caratteri (i segni)
    short int getWeight(char c);

    void topAndPop(std::stack<long double>& nums, std::stack<char>& sign);   //Codice contenuto in un paio di cicli while, legge e cancella gli elementi dello stack
    long double evaluateStep(long double a, long double b, char sign);     //Calcola gli elementi passati per parametro, usato in combinazione con topAndPop(...)

    //General flags
    bool divByZero = false; //Division by 0 flag
    bool isValid = true;    //Usata per le corrispondenze tra parentesi

    short int mismatchedP = 0;  //When a '(' is opened, this is incremented. When closed, it's decremented. If it's != 0, there is a parentesys mismatch (fix avaiable, see math.cpp)


    long double highResResult;

    //bool scientific = true;
};

#endif // SCIENTIFICENGINE_H
