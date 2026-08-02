#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initial setup
    ui->calcDisplay->hide();

    ptr_Math = new Math(this);

    //Instance of Math class

    for(int i = 0; i <= 9; i++)
    {
        QString buttonName = QString("pushButton_%1").arg(i);
        QPushButton *button = ui->centralwidget->findChild<QPushButton*>(buttonName);

        if(button)
        {
            char value = '0' + i;
            QObject::connect(button, &QPushButton::released, ptr_Math, [this, value]() {ptr_Math->on_pushButton_released(value);});
        }
    }

    QObject::connect(ui->pushButton_nigga, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('N'); });

    QObject::connect(ui->pushButton_add, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('+'); });
    QObject::connect(ui->pushButton_sub, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('-'); });
    QObject::connect(ui->pushButton_mul, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('*'); });
    QObject::connect(ui->pushButton_div, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('/'); });
    QObject::connect(ui->pushButton_equal, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('='); });

    QObject::connect(ui->pushButton_del, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('C'); });
    QObject::connect(ui->pushButton_delAll, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('D'); });
    QObject::connect(ui->pushButton_decimal, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('.'); });

            //New buttons, will be implemeted gradually
    //QObject::connect(ui->pushButton_negative, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('_');});
    QObject::connect(ui->pushButton_module, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('%');});
    //QObject::connect(ui->pushButton_open, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('(');});
    //QObject::connect(ui->pushButton_close, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released(')');});

    QObject::connect(ui->pushButton_pot, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('^');});

    QObject::connect(ui->pushButton_s, &QPushButton::toggled, [this]() {ptr_Math->specialToggled();});

    //End of widget connections


    QObject::connect(ptr_Math, &Math::contentUpdated, this, [this](const QString content, bool scientific) {this->updateDisplay(content, scientific); });
    QObject::connect(ptr_Math, &Math::scientificToggled, this, [this](const bool scientific) {this->updateScientificMode(scientific); });      //Update display LCD
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::updateDisplay(QString content, bool scientific)
{
    if(!scientific)
    {
        this->ui->lcdNumberOld->display(content);
    }
    else
    {
        this->ui->calcDisplay->setText(content);
    }
}

void MainWindow::updateScientificMode(bool scientific)
{
    if(!scientific)
    {
        this->ui->calcDisplay->hide();
        this->ui->lcdNumberOld->show();
    }
    else
    {
        this->ui->calcDisplay->show();
        this->ui->lcdNumberOld->hide();
    }
}