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
    QObject::connect(ui->pushButton_module, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('%');});
    QObject::connect(ui->pushButton_equal, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('='); });

    QObject::connect(ui->pushButton_del, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('C'); });
    QObject::connect(ui->pushButton_delAll, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('D'); });
    QObject::connect(ui->pushButton_decimal, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('.'); });

            //New buttons, will be implemeted gradually
    //QObject::connect(ui->pushButton_negative, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('_');});
    //QObject::connect(ui->pushButton_factorial, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('r');});

    QObject::connect(ui->pushButton_openParentesys, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('(');});
    QObject::connect(ui->pushButton_closeParentesys, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released(')');});

    QObject::connect(ui->pushButton_pot, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('^');});
    QObject::connect(ui->pushButton_potSquare, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('2');});

    //QObject::connect(ui->pushButton_anyRoot, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('R');});
    //QObject::connect(ui->pushButton_sqrt, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('r');});

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
    //this->ui->lcdNumber->display(content);
    //this->ui->calcDisplay->setText(content);


    if(!scientific)
    {
        this->ui->lcdNumberOld->display(content);
    }
    else
    {
        this->ui->calcDisplay->setText(content);
    }

    qDebug() << "2>Scientific flag:" << scientific;
}

void MainWindow::updateScientificMode(bool scientific)
{
    if(!scientific)
    {
        this->ui->calcDisplay->hide();
        this->ui->lcdNumberOld->show();

        this->ui->pushButton_openParentesys->setEnabled(false);
        this->ui->pushButton_closeParentesys->setEnabled(false);
        this->ui->pushButton_s->setText("NORMAL");
        this->ui->pushButton_s->setStyleSheet("background-color: rgb(131, 98, 0)");
    }
    else
    {
        this->ui->calcDisplay->show();
        this->ui->lcdNumberOld->hide();

        this->ui->pushButton_openParentesys->setEnabled(true);
        this->ui->pushButton_closeParentesys->setEnabled(true);
        this->ui->pushButton_s->setText("ADV");
        this->ui->pushButton_s->setStyleSheet("background-color:green");
    }

    qDebug() << "Scientific flag:" << scientific;
}