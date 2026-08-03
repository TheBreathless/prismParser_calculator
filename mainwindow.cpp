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

    for(int i = 0; i <= 9; i++) //Assign at each pushButton_n a value (example: pressing pushButton_1 output 1, etc...)
    {
        QString buttonName = QString("pushButton_%1").arg(i);
        QPushButton *button = ui->centralwidget->findChild<QPushButton*>(buttonName);

        if(button)
        {
            char value = '0' + i;
            QObject::connect(button, &QPushButton::released, ptr_Math, [this, value]() {ptr_Math->on_pushButton_released(value);});
        }
    }

    QObject::connect(ui->pushButton_nigga, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('N'); });   //This is the HELP button

    QObject::connect(ui->pushButton_add, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('+'); });
    QObject::connect(ui->pushButton_sub, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('-'); });
    QObject::connect(ui->pushButton_mul, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('*'); });
    QObject::connect(ui->pushButton_div, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('/'); });
    QObject::connect(ui->pushButton_module, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('%');});
    QObject::connect(ui->pushButton_equal, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('='); });

    QObject::connect(ui->pushButton_del, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('C'); }); //del char
    QObject::connect(ui->pushButton_delAll, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('D'); });  //del all
    QObject::connect(ui->pushButton_decimal, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('.'); });

            //New buttons, will be implemeted gradually
    //QObject::connect(ui->pushButton_negative, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('_');});
    //QObject::connect(ui->pushButton_factorial, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('!');});

    QObject::connect(ui->pushButton_openParentesys, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('(');});
    QObject::connect(ui->pushButton_closeParentesys, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released(')');});

    QObject::connect(ui->pushButton_pot, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('^');});
    QObject::connect(ui->pushButton_potSquare, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('s');});

    QObject::connect(ui->pushButton_pi, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('P');});

    //QObject::connect(ui->pushButton_anyRoot, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('R');});
    QObject::connect(ui->pushButton_sqrt, &QPushButton::released, ptr_Math, [this]() {ptr_Math->on_pushButton_released('r');});

    QObject::connect(ui->pushButton_s, &QPushButton::toggled, [this]() {ptr_Math->specialToggled();});  //Scientific calculator toggler

    //End of widget connections


    QObject::connect(ptr_Math, &Math::contentUpdated, this, [this](const QString content, bool scientific) {this->updateDisplay(content, scientific); });  //Update display
    QObject::connect(ptr_Math, &Math::scientificToggled, this, [this](const bool scientific) {this->updateScientificMode(scientific); });      //Update scientific mode
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

    this->ui->pushButton_sqrt->setEnabled(scientific);
    //this->ui->pushButton_anyRoot->setEnabled(scientific);
}