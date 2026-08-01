#include "mainwindow.h"

#include <QApplication>

//Nothing to see here

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle("Calcolatrice pazzurda");

    w.show();
    return QCoreApplication::exec();
}