#ifndef MATH_H
#define MATH_H

#pragma once
#include <QObject>
#include <QWidget>
#include <QMessageBox>
#include <QMessageBox.h>

#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>

#include <vector>
#include <fstream>

#include <stack>
#include <cctype>
#include <string>


//#define INDEX_MAX 64    //Max operations that can be performed in a single '=' press. Was used by iteration 5, but it's now obsolete

class Math: public QObject
{
    Q_OBJECT        //Macro for Qt

public:
    Math();     //Default class constructor

    explicit Math(QObject *parent = nullptr);

    void simpleMath();      //Same as testCalculateResult(), but for future versions
    void advancedMath();    //Future implementation of scientific calculator

    QString subCalculation(QString string);
    QString subResult(QString string);

    void testCalculateResult();     //Calculate results, only for debug

public slots:
    void on_pushButton_released(char value);    //One of the QPushButton has been pressed, value is the identifier of that button
    void specialToggled();

signals:
    void contentUpdated(QString content, bool scientific);   //Signals that the ldc widget has to be updated
    void scientificToggled(bool scientific);

private:
    void registerCalculation(char value);   //Used for default calculator mode, saves all values into registers
    void stringCalculation(char value);     //>> for scientific >> mode, currently not finished

    void clearLast();
    void clearAll();

    bool scientific = false;

    QString displayed;    //Value displayed, converted to double before being saved to a register
    QString operationString;

    std::vector<double> registers;  //Vector of numbers that will be calculated with this->sign;
    std::vector<char> sign {'+'};         //Order of operations: sign[i], register[i], sign[i+1], register[i+1]...

    double ah, al;      //Traditional calculator registers, but allowed only few operations without pemdas
    double bh, bl;      //

    double result;      //Used by all calculator modes

    bool newValue = false;      //Checks if a new numeric value has been inserted or the last sign has to be changed
    bool isDecimal = false;     //Check if the value has already decimal numbers. If true, the decimal point input is ignored


    //Parser-related functions
    double solveString(QString string);

    short int getWeight(char c);
    double evaluateStep(double a, double b, char sign);     //Calcola gli elementi passati per parametro, usato in combinazione con topAndPop(...)

    void topAndPop(std::stack<double>& nums, std::stack<char>& sign);   //Codice contenuto in un paio di cicli while, legge e cancella gli elementi dello stack

    bool isSign(char c);    //Controlla se c fa parte di un gruppo arbitrario di caratteri (i segni)

    bool divByZero = false;
    bool isValid = true;    //Usata per le corrispondenze tra parentesi


    //Msg boxes
    void msgCatanzaro();
    void msgSubscription();
    void msgNotImplemented();
    void msgHelp1();

    //Easter eggs
    void showEasterEgg1();
};
#endif //MATH_H