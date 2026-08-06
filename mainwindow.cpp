#include "math.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initial setup: if lcdDisplay is shown, calcDisplay is hidden and vice versa. Handled by updateScientificMode
    ui->calcDisplay->hide();    //calcDisplay is the display for scientific operations. If the scientific mode is disabled, the output is lcdDisplay (you can see it by toggling)

    ptr_Math = new Math(this);  //Instance of Math class


    const auto buttons = ui->centralwidget->findChildren<QPushButton*>(QString(), Qt::FindDirectChildrenOnly);

    for (QPushButton *button : buttons) {
        const QVariant propValue = button->property("value");

        if (propValue.isValid()) {
            const char value = propValue.toChar().toLatin1();

            if (value != '\0') {
                QObject::connect(button, &QPushButton::released, this, [this, value]() {
                    ptr_Math->on_pushButton_released(value);
                });
            }
        }
    }

    QObject::connect(ui->pushButton_s, &QPushButton::toggled, ptr_Math, &Math::specialToggled);
    QObject::connect(ptr_Math, &Math::contentUpdated, this, &MainWindow::updateDisplay);
    QObject::connect(ptr_Math, &Math::scientificToggled, this, &MainWindow::updateScientificMode);
}

MainWindow::~MainWindow()   //Class destructor
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
        if(content.toStdString() == "DIVISION BY 0")
        {
            this->ui->warningBox->setText("Division by 0");
            content.assign("MATH ERROR");
        }
        else if(content.contains("SYNTAX ERROR"))
            this->ui->warningBox->setText("Sintassi non valida");
        else if(content.toDouble() > 1e14)
            this->ui->warningBox->setText("Possibile perdita di precisione");
        else if(content.toDouble() < 1e14)
            this->ui->warningBox->clear();

        this->ui->calcDisplay->setText(content);
    }
}

void MainWindow::updateScientificMode(bool scientific)
{
    if(!scientific)
    {
        this->ui->calcDisplay->hide();
        this->ui->lcdNumberOld->show();

        this->ui->pushButton_s->setText("NORMAL");
        this->ui->pushButton_s->setStyleSheet("background-color: rgb(131, 98, 0)");
    }
    else
    {
        this->ui->calcDisplay->show();
        this->ui->lcdNumberOld->hide();

        this->ui->pushButton_s->setText("ADV");
        this->ui->pushButton_s->setStyleSheet("background-color:green");
    }

    this->ui->pushButton_openParentesys->setEnabled(scientific);
    this->ui->pushButton_closeParentesys->setEnabled(scientific);

    this->ui->pushButton_potSquare->setEnabled(scientific);
    this->ui->pushButton_pi->setEnabled(scientific);
    this->ui->pushButton_e->setEnabled(scientific);

    this->ui->pushButton_sqrt->setEnabled(scientific);
    //this->ui->pushButton_anyRoot->setEnabled(scientific);
}