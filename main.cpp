#include "mainwindow.h"

#include <QApplication>

//Nothing to see here

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QString nigga = "15+²√(3)-1";
    qDebug() << nigga;

    nigga.replace("²√(", "(");
    nigga.replace(")", ")^(1/2)");

    qDebug() << nigga;

    w.setWindowTitle("Calcolatrice pazzurda");

    w.show();
    return QCoreApplication::exec();
}