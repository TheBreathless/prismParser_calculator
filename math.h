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
#include <QFileInfo>

#include <vector>
#include <fstream>

#include <stack>
#include <cctype>
#include <string>

#define DEFAULT_PI "3.14159265"
#define HIGH_PRES_PI "3.141592653589793"


class Math: public QObject
{
    Q_OBJECT        //Macro for Qt

public:
    Math();     //Default class constructor

    explicit Math(QObject *parent = nullptr);

public slots:
    void on_pushButton_released(char value);    //One of the QPushButton has been pressed, value is the identifier of that button
    void specialToggled();

signals:
    void contentUpdated(QString content, bool scientific);   //Signals that the ldc widget has to be updated
    void scientificToggled(bool scientific);

private:
    void testCalculateResult();     //Calculate results, only for debug //Update: its used for sequential operations

    void registerCalculation(char value);   //Used for default calculator mode, saves all values into registers
    void scientificCalculation(char value);     //>> for scientific >> mode, currently not finished

    void clearLast();   //Clean last char
    void clearAll();    //Reset all registers and variables, both for scientific and non scientific mode

    bool scientific = false;    //Scientific flag, determine how the operations are saved and wich algorithm will be used to evaluate them

    QString displayed;    //Value displayed, converted to double before being saved to a register
    QString operationString;

    std::vector<double> registers;  //Vector of numbers that will be calculated with this->sign;
    std::vector<char> sign {'+'};   //The first sign is always a +. Signed operations arent supported (to write -5 you have to do +0-5)

    double result;      //Used by all calculator modes

    bool newValue = false;      //Checks if a new numeric value has been inserted or the last sign has to be changed
    bool isDecimal = false;     //Check if the value has already decimal numbers. If true, the decimal point input is ignored


    //Parser-related functions
    long double parseString(QString string);
    bool translateString(QString& string);

    short int getWeight(char c);
    long double evaluateStep(long double a, long double b, char sign);     //Calcola gli elementi passati per parametro, usato in combinazione con topAndPop(...)

    void topAndPop(std::stack<long double>& nums, std::stack<char>& sign);   //Codice contenuto in un paio di cicli while, legge e cancella gli elementi dello stack

    bool isSign(char c);    //Controlla se c fa parte di un gruppo arbitrario di caratteri (i segni)

    bool divByZero = false; //Division by 0 flag
    bool isValid = true;    //Usata per le corrispondenze tra parentesi

    short int mismatchedP = 0;  //When a '(' is opened, this is incremented. When closed, it's decremented. If it's != 0, there is a parentesys mismatch (fix avaiable, see math.cpp)


    //Msg boxes
    void msgCatanzaro();
    void msgSubscription();
    void msgNotImplemented();
    void msgHelp1();

    //Easter eggs
    void showEasterEgg1();

    void genericVideoPlay(QString url); //Basic video player that takes an url as parameter. Display both video and audio.
};
#endif //MATH_H