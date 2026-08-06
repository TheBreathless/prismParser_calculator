#ifndef MATH_H
#define MATH_H

#include <QObject>
#include <QWidget>

#include <vector>
#include <fstream>

#include <cctype>

class ScientificEngine;
class MediaEngine;

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
    ScientificEngine *scientificEngine_ptr = nullptr;
    MediaEngine *mediaEngine_ptr = nullptr;

    QString displayed;    //Value displayed, converted to double before being saved to a register
    QString operationString;

    std::vector<double> registers;  //Vector of numbers that will be calculated with sign vector;
    std::vector<char> sign {'+'};   //The first sign is always a +. Signed operations arent supported (to write -5 you have to do +0-5)

    double result;              //Used by all calculator modes
    long double highResResult;  //Sperimental

    bool newValue = false;      //Checks if a new numeric value has been inserted or the last sign has to be changed
    bool isDecimal = false;     //Check if the value has already decimal numbers. If true, the decimal point input is ignored
    bool scientific = false;    //Scientific flag, determine how the operations are saved and wich algorithm will be used to evaluate them

    short int bufferedSign = 0;

    void evaluateRegisters();     //Calculate results, only for debug //Update: its used for sequential operations

    void registerCalculation(char value);       //Used for default calculator mode, saves all values into registers
    void operateScientificMode(char value);     //>> for scientific >> mode, currently not finished

    void clearLast();   //Clean last char
    void clearAll();    //Reset all registers and variables, both for scientific and non scientific mode

    //bool isSign(char c);    //Controlla se c fa parte di un gruppo arbitrario di caratteri (i segni)

    short int mismatchedP = 0;  //When a '(' is opened, this is incremented. When closed, it's decremented. If it's != 0, there is a parentesys mismatch (fix avaiable, see math.cpp)
};
#endif //MATH_H