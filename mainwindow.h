#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include <QMainWindow>
#include "math.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

public slots:
    void updateDisplay(QString content, bool scientific);
    void updateScientificMode(bool scientific);

signals:
    void pushButton_clicked(int num);   //Check implementation in .cpp

private:
    Ui::MainWindow *ui;
    Math *ptr_Math;

    QString contentDisplayed;
};
#endif // MAINWINDOW_H