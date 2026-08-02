/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *calcDisplay;
    QLCDNumber *lcdNumberOld;
    QGridLayout *gridLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_sub;
    QPushButton *pushButton_16;
    QPushButton *pushButton_8;
    QPushButton *pushButton_0;
    QPushButton *pushButton_decimal;
    QPushButton *pushButton_s;
    QPushButton *pushButton_div;
    QPushButton *pushButton_15;
    QPushButton *pushButton_potSquare;
    QPushButton *pushButton_openParentesys;
    QPushButton *pushButton_factorial;
    QPushButton *pushButton_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_pi;
    QPushButton *pushButton_5;
    QPushButton *pushButton_del;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton;
    QPushButton *pushButton_1;
    QPushButton *pushButton_module;
    QPushButton *pushButton_delAll;
    QPushButton *pushButton_9;
    QPushButton *pushButton_equal;
    QPushButton *pushButton_closeParentesys;
    QPushButton *pushButton_6;
    QPushButton *pushButton_pot;
    QPushButton *pushButton_nigga;
    QPushButton *pushButton_4;
    QPushButton *pushButton_anyRoot;
    QPushButton *pushButton_add;
    QPushButton *pushButton_mul;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(362, 632);
        MainWindow->setMinimumSize(QSize(325, 450));
        QFont font;
        font.setFamilies({QString::fromUtf8("Cascadia Code")});
        font.setBold(true);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        MainWindow->setDockOptions(QMainWindow::DockOption::AllowTabbedDocks|QMainWindow::DockOption::AnimatedDocks);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(12);
        verticalLayout_2->setObjectName("verticalLayout_2");
        calcDisplay = new QLabel(centralwidget);
        calcDisplay->setObjectName("calcDisplay");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(calcDisplay->sizePolicy().hasHeightForWidth());
        calcDisplay->setSizePolicy(sizePolicy);
        calcDisplay->setMinimumSize(QSize(300, 75));
        calcDisplay->setMaximumSize(QSize(2000, 75));
        calcDisplay->setSizeIncrement(QSize(4, 1));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cascadia Code")});
        font1.setPointSize(27);
        font1.setWeight(QFont::DemiBold);
        font1.setItalic(false);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        calcDisplay->setFont(font1);
        calcDisplay->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        calcDisplay->setAutoFillBackground(false);
        calcDisplay->setFrameShape(QFrame::Shape::StyledPanel);
        calcDisplay->setFrameShadow(QFrame::Shadow::Sunken);
        calcDisplay->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        calcDisplay->setWordWrap(false);

        verticalLayout_2->addWidget(calcDisplay);

        lcdNumberOld = new QLCDNumber(centralwidget);
        lcdNumberOld->setObjectName("lcdNumberOld");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(lcdNumberOld->sizePolicy().hasHeightForWidth());
        lcdNumberOld->setSizePolicy(sizePolicy1);
        lcdNumberOld->setMinimumSize(QSize(300, 75));
        lcdNumberOld->setMaximumSize(QSize(2000, 75));
        lcdNumberOld->setSizeIncrement(QSize(4, 1));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Cascadia Mono")});
        font2.setBold(true);
        lcdNumberOld->setFont(font2);
        lcdNumberOld->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lcdNumberOld->setAutoFillBackground(false);
        lcdNumberOld->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        lcdNumberOld->setFrameShape(QFrame::Shape::Box);
        lcdNumberOld->setFrameShadow(QFrame::Shadow::Raised);
        lcdNumberOld->setSmallDecimalPoint(false);
        lcdNumberOld->setDigitCount(12);
        lcdNumberOld->setSegmentStyle(QLCDNumber::SegmentStyle::Filled);
        lcdNumberOld->setProperty("intValue", QVariant(0));

        verticalLayout_2->addWidget(lcdNumberOld);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(2);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(2, 0, 2, 0);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);
        pushButton_3->setMinimumSize(QSize(50, 50));
        pushButton_3->setMaximumSize(QSize(16777215, 16777215));
        pushButton_3->setSizeIncrement(QSize(1, 1));
        pushButton_3->setBaseSize(QSize(50, 50));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Cascadia Code")});
        font3.setPointSize(12);
        font3.setBold(true);
        pushButton_3->setFont(font3);
        pushButton_3->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_3->setAutoFillBackground(false);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(0, 85, 125);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(0, 65, 125);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(0, 50, 125);\n"
"}"));
        pushButton_3->setIconSize(QSize(16, 16));
        pushButton_3->setCheckable(false);
        pushButton_3->setAutoRepeat(false);
        pushButton_3->setAutoDefault(false);
        pushButton_3->setFlat(false);

        gridLayout->addWidget(pushButton_3, 4, 2, 1, 1);

        pushButton_sub = new QPushButton(centralwidget);
        pushButton_sub->setObjectName("pushButton_sub");
        pushButton_sub->setEnabled(true);
        sizePolicy2.setHeightForWidth(pushButton_sub->sizePolicy().hasHeightForWidth());
        pushButton_sub->setSizePolicy(sizePolicy2);
        pushButton_sub->setMinimumSize(QSize(50, 50));
        pushButton_sub->setSizeIncrement(QSize(1, 1));
        pushButton_sub->setBaseSize(QSize(50, 50));
        pushButton_sub->setFont(font3);
        pushButton_sub->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 25, 130);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(0, 15, 110);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(0, 10, 100); \n"
"}"));
        pushButton_sub->setCheckable(false);
        pushButton_sub->setAutoRepeat(false);
        pushButton_sub->setAutoDefault(false);
        pushButton_sub->setFlat(false);

        gridLayout->addWidget(pushButton_sub, 5, 3, 1, 1);

        pushButton_16 = new QPushButton(centralwidget);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setEnabled(false);
        sizePolicy2.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy2);
        pushButton_16->setMinimumSize(QSize(50, 50));
        pushButton_16->setSizeIncrement(QSize(1, 1));
        pushButton_16->setBaseSize(QSize(50, 50));
        pushButton_16->setFont(font3);
        pushButton_16->setFlat(false);

        gridLayout->addWidget(pushButton_16, 8, 0, 1, 1);

        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setEnabled(true);
        sizePolicy2.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy2);
        pushButton_8->setMinimumSize(QSize(50, 50));
        pushButton_8->setMaximumSize(QSize(16777215, 16777215));
        pushButton_8->setSizeIncrement(QSize(1, 1));
        pushButton_8->setBaseSize(QSize(50, 50));
        pushButton_8->setFont(font3);
        pushButton_8->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_8->setAutoFillBackground(false);
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(0, 85, 125);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(0, 65, 125);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(0, 50, 125);\n"
"}"));
        pushButton_8->setIconSize(QSize(16, 16));
        pushButton_8->setCheckable(false);
        pushButton_8->setAutoRepeat(false);
        pushButton_8->setAutoDefault(false);
        pushButton_8->setFlat(false);

        gridLayout->addWidget(pushButton_8, 6, 1, 1, 1);

        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName("pushButton_0");
        pushButton_0->setEnabled(true);
        sizePolicy2.setHeightForWidth(pushButton_0->sizePolicy().hasHeightForWidth());
        pushButton_0->setSizePolicy(sizePolicy2);
        pushButton_0->setMinimumSize(QSize(50, 50));
        pushButton_0->setMaximumSize(QSize(16777215, 16777215));
        pushButton_0->setSizeIncrement(QSize(1, 1));
        pushButton_0->setBaseSize(QSize(50, 50));
        pushButton_0->setFont(font3);
        pushButton_0->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_0->setAutoFillBackground(false);
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(0, 85, 125);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(0, 65, 125);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(0, 50, 125);\n"
"}"));
        pushButton_0->setIconSize(QSize(16, 16));
        pushButton_0->setCheckable(false);
        pushButton_0->setAutoRepeat(false);
        pushButton_0->setAutoDefault(false);
        pushButton_0->setFlat(false);

        gridLayout->addWidget(pushButton_0, 7, 1, 1, 1);

        pushButton_decimal = new QPushButton(centralwidget);
        pushButton_decimal->setObjectName("pushButton_decimal");
        pushButton_decimal->setEnabled(true);
        sizePolicy2.setHeightForWidth(pushButton_decimal->sizePolicy().hasHeightForWidth());
        pushButton_decimal->setSizePolicy(sizePolicy2);
        pushButton_decimal->setMinimumSize(QSize(50, 50));
        pushButton_decimal->setSizeIncrement(QSize(1, 1));
        pushButton_decimal->setBaseSize(QSize(50, 50));
        pushButton_decimal->setFont(font3);
        pushButton_decimal->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(0, 85, 125);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(0, 65, 125);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(0, 50, 125);\n"
"}"));
        pushButton_decimal->setCheckable(false);
        pushButton_decimal->setAutoRepeat(false);
        pushButton_decimal->setAutoDefault(false);
        pushButton_decimal->setFlat(false);

        gridLayout->addWidget(pushButton_decimal, 7, 2, 1, 1);

        pushButton_s = new QPushButton(centralwidget);
        pushButton_s->setObjectName("pushButton_s");
        pushButton_s->setEnabled(true);
        pushButton_s->setMinimumSize(QSize(50, 50));
        pushButton_s->setSizeIncrement(QSize(1, 1));
        pushButton_s->setBaseSize(QSize(50, 50));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Cascadia Code")});
        font4.setPointSize(11);
        font4.setBold(true);
        pushButton_s->setFont(font4);
        pushButton_s->setAutoFillBackground(false);
        pushButton_s->setStyleSheet(QString::fromUtf8("background-color: rgb(130, 100, 0);"));
        pushButton_s->setCheckable(true);
        pushButton_s->setChecked(false);
        pushButton_s->setAutoRepeat(false);
        pushButton_s->setAutoDefault(true);
        pushButton_s->setFlat(false);

        gridLayout->addWidget(pushButton_s, 7, 0, 1, 1);

        pushButton_div = new QPushButton(centralwidget);
        pushButton_div->setObjectName("pushButton_div");
        pushButton_div->setEnabled(true);
        sizePolicy2.setHeightForWidth(pushButton_div->sizePolicy().hasHeightForWidth());
        pushButton_div->setSizePolicy(sizePolicy2);
        pushButton_div->setMinimumSize(QSize(50, 50));
        pushButton_div->setSizeIncrement(QSize(1, 1));
        pushButton_div->setBaseSize(QSize(50, 50));
        pushButton_div->setFont(font3);
        pushButton_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 25, 130);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(0, 15, 110);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(0, 10, 100); \n"
"}"));
        pushButton_div->setIconSize(QSize(16, 16));
        pushButton_div->setCheckable(false);
        pushButton_div->setAutoRepeat(false);
        pushButton_div->setAutoDefault(false);
        pushButton_div->setFlat(false);

        gridLayout->addWidget(pushButton_div, 2, 3, 1, 1);

        pushButton_15 = new QPushButton(centralwidget);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setEnabled(false);
        sizePolicy2.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy2);
        pushButton_15->setMinimumSize(QSize(50, 50));
        pushButton_15->setSizeIncrement(QSize(1, 1));
        pushButton_15->setBaseSize(QSize(50, 50));
        pushButton_15->setFont(font3);
        pushButton_15->setFlat(false);

        gridLayout->addWidget(pushButton_15, 8, 1, 1, 1);

        pushButton_potSquare = new QPushButton(centralwidget);
        pushButton_potSquare->setObjectName("pushButton_potSquare");
        pushButton_potSquare->setEnabled(false);
        sizePolicy2.setHeightForWidth(pushButton_potSquare->sizePolicy().hasHeightForWidth());
        pushButton_potSquare->setSizePolicy(sizePolicy2);
        pushButton_potSquare->setMinimumSize(QSize(50, 50));
        pushButton_potSquare->setSizeIncrement(QSize(1, 1));
        pushButton_potSquare->setBaseSize(QSize(50, 50));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Cascadia Code")});
        font5.setPointSize(14);
        font5.setBold(true);
        pushButton_potSquare->setFont(font5);
        pushButton_potSquare->setFlat(false);

        gridLayout->addWidget(pushButton_potSquare, 0, 2, 1, 1);

        pushButton_openParentesys = new QPushButton(centralwidget);
        pushButton_openParentesys->setObjectName("pushButton_openParentesys");
        pushButton_openParentesys->setEnabled(false);
        sizePolicy2.setHeightForWidth(pushButton_openParentesys->sizePolicy().hasHeightForWidth());
        pushButton_openParentesys->setSizePolicy(sizePolicy2);
        pushButton_openParentesys->setMinimumSize(QSize(50, 50));
        pushButton_openParentesys->setSizeIncrement(QSize(1, 1));
        pushButton_openParentesys->setBaseSize(QSize(50, 50));
        pushButton_openParentesys->setFont(font3);
        pushButton_openParentesys->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(0, 0, 90);"));
        pushButton_openParentesys->setFlat(false);

        gridLayout->addWidget(pushButton_openParentesys, 1, 0, 1, 1);

        pushButton_factorial = new QPushButton(centralwidget);
        pushButton_factorial->setObjectName("pushButton_factorial");
        pushButton_factorial->setEnabled(false);
        sizePolicy2.setHeightForWidth(pushButton_factorial->sizePolicy().hasHeightForWidth());
        pushButton_factorial->setSizePolicy(sizePolicy2);
        pushButton_factorial->setMinimumSize(QSize(50, 50));
        pushButton_factorial->setSizeIncrement(QSize(1, 1));
        pushButton_factorial->setBaseSize(QSize(50, 50));
        pushButton_factorial->setFont(font5);
        pushButton_factorial->setFlat(false);

        gridLayout->addWidget(pushButton_factorial, 0, 3, 1, 1);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setEnabled(true);
        sizePolicy2.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy2);
        pushButton_7->setMinimumSize(QSize(50, 50));
        pushButton_7->setMaximumSize(QSize(16777215, 16777215));
        pushButton_7->setSizeIncrement(QSize(1, 1));
        pushButton_7->setBaseSize(QSize(50, 50));
        pushButton_7->setFont(font3);
        pushButton_7->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_7->setAutoFillBackground(false);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(0, 85, 125);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(0, 65, 125);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(0, 50, 125);\n"
"}"));
        pushButton_7->setIconSize(QSize(16, 16));
        pushButton_7->setCheckable(false);
        pushButton_7->setAutoRepeat(false);
        pushButton_7->setAutoDefault(false);
        pushButton_7->setFlat(false);

        gridLayout->addWidget(pushButton_7, 6, 0, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setEnabled(true);
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);
        pushButton_2->setMinimumSize(QSize(50, 50));
        pushButton_2->setMaximumSize(QSize(16777215, 16777215));
        pushButton_2->setSizeIncrement(QSize(1, 1));
        pushButton_2->setBaseSize(QSize(50, 50));
        pushButton_2->setFont(font3);
        pushButton_2->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_2->setAutoFillBackground(false);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(0, 85, 125);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(0, 65, 125);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(0, 50, 125);\n"
"}"));
        pushButton_2->setIconSize(QSize(16, 16));
        pushButton_2->setCheckable(false);
        pushButton_2->setAutoRepeat(false);
        pushButton_2->setAutoDefault(false);
        pushButton_2->setFlat(false);

        gridLayout->addWidget(pushButton_2, 4, 1, 1, 1);

        pushButton_pi = new QPushButton(centralwidget);
        pushButton_pi->setObjectName("pushButton_pi");
        pushButton_pi->setEnabled(false);
        sizePolicy2.setHeightForWidth(pushButton_pi->sizePolicy().hasHeightForWidth());
        pushButton_pi->setSizePolicy(sizePolicy2);
        pushButton_pi->setMinimumSize(QSize(50, 50));
        pushButton_pi->setSizeIncrement(QSize(1, 1));
        pushButton_pi->setBaseSize(QSize(50, 50));
        pushButton_pi->setFont(font5);
        pushButton_pi->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 25, 130);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(0, 15, 110);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(0, 10, 100); \n"
"}"));
        pushButton_pi->setFlat(false);

        gridLayout->addWidget(pushButton_pi, 8, 2, 1, 1);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setEnabled(true);
        sizePolicy2.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy2);
        pushButton_5->setMinimumSize(QSize(50, 50));
        pushButton_5->setMaximumSize(QSize(16777215, 16777215));
        pushButton_5->setSizeIncrement(QSize(1, 1));
        pushButton_5->setBaseSize(QSize(50, 50));
        pushButton_5->setFont(font3);
        pushButton_5->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_5->setAutoFillBackground(false);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(0, 85, 125);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(0, 65, 125);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(0, 50, 125);\n"
"}"));
        pushButton_5->setIconSize(QSize(16, 16));
        pushButton_5->setCheckable(false);
        pushButton_5->setAutoRepeat(false);
        pushButton_5->setAutoDefault(false);
        pushButton_5->setFlat(false);

        gridLayout->addWidget(pushButton_5, 5, 1, 1, 1, Qt::AlignmentFlag::AlignVCenter);

        pushButton_del = new QPushButton(centralwidget);
        pushButton_del->setObjectName("pushButton_del");
        pushButton_del->setEnabled(true);
        sizePolicy2.setHeightForWidth(pushButton_del->sizePolicy().hasHeightForWidth());
        pushButton_del->setSizePolicy(sizePolicy2);
        pushButton_del->setMinimumSize(QSize(50, 50));
        pushButton_del->setSizeIncrement(QSize(1, 1));
        pushButton_del->setBaseSize(QSize(50, 50));
        pushButton_del->setFont(font3);
        pushButton_del->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 25, 130);\n"
"	color: rgb(220, 0, 0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(0, 15, 110);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(0, 10, 100); \n"
"}"));
        pushButton_del->setCheckable(false);
        pushButton_del->setAutoRepeat(false);
        pushButton_del->setAutoDefault(false);
        pushButton_del->setFlat(false);

        gridLayout->addWidget(pushButton_del, 2, 2, 1, 1);

        pushButton_sqrt = new QPushButton(centralwidget);
        pushButton_sqrt->setObjectName("pushButton_sqrt");
        pushButton_sqrt->setEnabled(false);
        sizePolicy2.setHeightForWidth(pushButton_sqrt->sizePolicy().hasHeightForWidth());
        pushButton_sqrt->setSizePolicy(sizePolicy2);
        pushButton_sqrt->setMinimumSize(QSize(50, 50));
        pushButton_sqrt->setSizeIncrement(QSize(1, 1));
        pushButton_sqrt->setBaseSize(QSize(50, 50));
        pushButton_sqrt->setFont(font5);
        pushButton_sqrt->setFlat(false);

        gridLayout->addWidget(pushButton_sqrt, 0, 1, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setEnabled(false);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMinimumSize(QSize(50, 50));
        pushButton->setSizeIncrement(QSize(1, 1));
        pushButton->setBaseSize(QSize(50, 50));
        pushButton->setFont(font3);
        pushButton->setFlat(false);

        gridLayout->addWidget(pushButton, 8, 3, 1, 1);

        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setEnabled(true);
        sizePolicy2.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy2);
        pushButton_1->setMinimumSize(QSize(50, 50));
        pushButton_1->setMaximumSize(QSize(16777215, 16777215));
        pushButton_1->setSizeIncrement(QSize(1, 1));
        pushButton_1->setBaseSize(QSize(50, 50));
        pushButton_1->setFont(font3);
        pushButton_1->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_1->setAutoFillBackground(false);
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(0, 85, 125);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(0, 65, 125);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(0, 50, 125);\n"
"}"));
        pushButton_1->setIconSize(QSize(16, 16));
        pushButton_1->setCheckable(false);
        pushButton_1->setAutoRepeat(false);
        pushButton_1->setAutoDefault(false);
        pushButton_1->setFlat(false);

        gridLayout->addWidget(pushButton_1, 4, 0, 1, 1);

        pushButton_module = new QPushButton(centralwidget);
        pushButton_module->setObjectName("pushButton_module");
        pushButton_module->setEnabled(true);
        pushButton_module->setMinimumSize(QSize(50, 50));
        pushButton_module->setSizeIncrement(QSize(1, 1));
        pushButton_module->setBaseSize(QSize(50, 50));
        pushButton_module->setFont(font3);
        pushButton_module->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(0, 0, 90);"));
        pushButton_module->setIconSize(QSize(16, 16));
        pushButton_module->setCheckable(false);

        gridLayout->addWidget(pushButton_module, 1, 3, 1, 1);

        pushButton_delAll = new QPushButton(centralwidget);
        pushButton_delAll->setObjectName("pushButton_delAll");
        pushButton_delAll->setEnabled(true);
        sizePolicy2.setHeightForWidth(pushButton_delAll->sizePolicy().hasHeightForWidth());
        pushButton_delAll->setSizePolicy(sizePolicy2);
        pushButton_delAll->setMinimumSize(QSize(50, 50));
        pushButton_delAll->setSizeIncrement(QSize(1, 1));
        pushButton_delAll->setBaseSize(QSize(50, 50));
        pushButton_delAll->setFont(font3);
        pushButton_delAll->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 25, 130);\n"
"	color: rgb(220, 0, 0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(0, 15, 110);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(0, 10, 100); \n"
"}"));
        pushButton_delAll->setCheckable(false);
        pushButton_delAll->setAutoRepeat(false);
        pushButton_delAll->setAutoDefault(false);
        pushButton_delAll->setFlat(false);

        gridLayout->addWidget(pushButton_delAll, 2, 1, 1, 1);

        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setEnabled(true);
        sizePolicy2.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy2);
        pushButton_9->setMinimumSize(QSize(50, 50));
        pushButton_9->setMaximumSize(QSize(16777215, 16777215));
        pushButton_9->setSizeIncrement(QSize(1, 1));
        pushButton_9->setBaseSize(QSize(50, 50));
        pushButton_9->setFont(font3);
        pushButton_9->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_9->setAutoFillBackground(false);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(0, 85, 125);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(0, 65, 125);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(0, 50, 125);\n"
"}"));
        pushButton_9->setIconSize(QSize(16, 16));
        pushButton_9->setCheckable(false);
        pushButton_9->setAutoRepeat(false);
        pushButton_9->setAutoDefault(false);
        pushButton_9->setFlat(false);

        gridLayout->addWidget(pushButton_9, 6, 2, 1, 1);

        pushButton_equal = new QPushButton(centralwidget);
        pushButton_equal->setObjectName("pushButton_equal");
        pushButton_equal->setEnabled(true);
        sizePolicy2.setHeightForWidth(pushButton_equal->sizePolicy().hasHeightForWidth());
        pushButton_equal->setSizePolicy(sizePolicy2);
        pushButton_equal->setMinimumSize(QSize(50, 50));
        pushButton_equal->setSizeIncrement(QSize(1, 1));
        pushButton_equal->setBaseSize(QSize(50, 50));
        pushButton_equal->setFont(font3);
        pushButton_equal->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 25, 130);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(0, 15, 110);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(0, 10, 100); \n"
"}"));
        pushButton_equal->setCheckable(false);
        pushButton_equal->setAutoRepeat(false);
        pushButton_equal->setAutoDefault(false);
        pushButton_equal->setFlat(false);

        gridLayout->addWidget(pushButton_equal, 7, 3, 1, 1);

        pushButton_closeParentesys = new QPushButton(centralwidget);
        pushButton_closeParentesys->setObjectName("pushButton_closeParentesys");
        pushButton_closeParentesys->setEnabled(false);
        sizePolicy2.setHeightForWidth(pushButton_closeParentesys->sizePolicy().hasHeightForWidth());
        pushButton_closeParentesys->setSizePolicy(sizePolicy2);
        pushButton_closeParentesys->setMinimumSize(QSize(50, 50));
        pushButton_closeParentesys->setSizeIncrement(QSize(1, 1));
        pushButton_closeParentesys->setBaseSize(QSize(50, 50));
        pushButton_closeParentesys->setFont(font3);
        pushButton_closeParentesys->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(0, 0, 90);"));
        pushButton_closeParentesys->setFlat(false);

        gridLayout->addWidget(pushButton_closeParentesys, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setEnabled(true);
        sizePolicy2.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy2);
        pushButton_6->setMinimumSize(QSize(50, 50));
        pushButton_6->setMaximumSize(QSize(16777215, 16777215));
        pushButton_6->setSizeIncrement(QSize(1, 1));
        pushButton_6->setBaseSize(QSize(50, 50));
        pushButton_6->setFont(font3);
        pushButton_6->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_6->setAutoFillBackground(false);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(0, 85, 125);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(0, 65, 125);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(0, 50, 125);\n"
"}"));
        pushButton_6->setIconSize(QSize(16, 16));
        pushButton_6->setCheckable(false);
        pushButton_6->setAutoRepeat(false);
        pushButton_6->setAutoDefault(false);
        pushButton_6->setFlat(false);

        gridLayout->addWidget(pushButton_6, 5, 2, 1, 1);

        pushButton_pot = new QPushButton(centralwidget);
        pushButton_pot->setObjectName("pushButton_pot");
        pushButton_pot->setEnabled(true);
        pushButton_pot->setMinimumSize(QSize(50, 50));
        pushButton_pot->setSizeIncrement(QSize(1, 1));
        pushButton_pot->setBaseSize(QSize(50, 50));
        pushButton_pot->setFont(font5);
        pushButton_pot->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(0, 0, 90);"));
        pushButton_pot->setIconSize(QSize(16, 16));
        pushButton_pot->setCheckable(false);
        pushButton_pot->setAutoDefault(false);
        pushButton_pot->setFlat(false);

        gridLayout->addWidget(pushButton_pot, 1, 2, 1, 1);

        pushButton_nigga = new QPushButton(centralwidget);
        pushButton_nigga->setObjectName("pushButton_nigga");
        pushButton_nigga->setEnabled(true);
        sizePolicy2.setHeightForWidth(pushButton_nigga->sizePolicy().hasHeightForWidth());
        pushButton_nigga->setSizePolicy(sizePolicy2);
        pushButton_nigga->setMinimumSize(QSize(50, 50));
        pushButton_nigga->setSizeIncrement(QSize(1, 1));
        pushButton_nigga->setBaseSize(QSize(50, 50));
        pushButton_nigga->setFont(font3);
        pushButton_nigga->setToolTipDuration(15);
        pushButton_nigga->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 25, 130);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(0, 15, 110);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(0, 10, 100); \n"
"}"));
        pushButton_nigga->setCheckable(false);
        pushButton_nigga->setAutoRepeat(false);
        pushButton_nigga->setAutoDefault(false);
        pushButton_nigga->setFlat(false);

        gridLayout->addWidget(pushButton_nigga, 2, 0, 1, 1);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setEnabled(true);
        sizePolicy2.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy2);
        pushButton_4->setMinimumSize(QSize(50, 50));
        pushButton_4->setMaximumSize(QSize(16777215, 16777215));
        pushButton_4->setSizeIncrement(QSize(1, 1));
        pushButton_4->setBaseSize(QSize(50, 50));
        pushButton_4->setFont(font3);
        pushButton_4->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_4->setAutoFillBackground(false);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(0, 85, 125);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(0, 65, 125);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(0, 50, 125);\n"
"}"));
        pushButton_4->setIconSize(QSize(16, 16));
        pushButton_4->setCheckable(false);
        pushButton_4->setAutoRepeat(false);
        pushButton_4->setAutoDefault(false);
        pushButton_4->setFlat(false);

        gridLayout->addWidget(pushButton_4, 5, 0, 1, 1);

        pushButton_anyRoot = new QPushButton(centralwidget);
        pushButton_anyRoot->setObjectName("pushButton_anyRoot");
        pushButton_anyRoot->setEnabled(false);
        sizePolicy2.setHeightForWidth(pushButton_anyRoot->sizePolicy().hasHeightForWidth());
        pushButton_anyRoot->setSizePolicy(sizePolicy2);
        pushButton_anyRoot->setMinimumSize(QSize(50, 50));
        pushButton_anyRoot->setSizeIncrement(QSize(1, 1));
        pushButton_anyRoot->setBaseSize(QSize(50, 50));
        pushButton_anyRoot->setFont(font5);
        pushButton_anyRoot->setFlat(false);

        gridLayout->addWidget(pushButton_anyRoot, 0, 0, 1, 1);

        pushButton_add = new QPushButton(centralwidget);
        pushButton_add->setObjectName("pushButton_add");
        pushButton_add->setEnabled(true);
        sizePolicy2.setHeightForWidth(pushButton_add->sizePolicy().hasHeightForWidth());
        pushButton_add->setSizePolicy(sizePolicy2);
        pushButton_add->setMinimumSize(QSize(50, 50));
        pushButton_add->setMaximumSize(QSize(16777215, 16777215));
        pushButton_add->setSizeIncrement(QSize(1, 1));
        pushButton_add->setBaseSize(QSize(50, 50));
        pushButton_add->setFont(font3);
        pushButton_add->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_add->setAutoFillBackground(false);
        pushButton_add->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 25, 130);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(0, 15, 110);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(0, 10, 100); \n"
"}"));
        pushButton_add->setIconSize(QSize(16, 16));
        pushButton_add->setCheckable(false);
        pushButton_add->setAutoRepeat(false);
        pushButton_add->setAutoDefault(false);
        pushButton_add->setFlat(false);

        gridLayout->addWidget(pushButton_add, 6, 3, 1, 1);

        pushButton_mul = new QPushButton(centralwidget);
        pushButton_mul->setObjectName("pushButton_mul");
        pushButton_mul->setEnabled(true);
        sizePolicy2.setHeightForWidth(pushButton_mul->sizePolicy().hasHeightForWidth());
        pushButton_mul->setSizePolicy(sizePolicy2);
        pushButton_mul->setMinimumSize(QSize(50, 50));
        pushButton_mul->setSizeIncrement(QSize(1, 1));
        pushButton_mul->setBaseSize(QSize(50, 50));
        pushButton_mul->setFont(font3);
        pushButton_mul->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 25, 130);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(0, 15, 110);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(0, 10, 100); \n"
"}"));
        pushButton_mul->setCheckable(false);
        pushButton_mul->setAutoRepeat(false);
        pushButton_mul->setAutoDefault(false);
        pushButton_mul->setFlat(false);

        gridLayout->addWidget(pushButton_mul, 4, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        pushButton_3->setDefault(true);
        pushButton_sub->setDefault(true);
        pushButton_16->setDefault(true);
        pushButton_8->setDefault(true);
        pushButton_0->setDefault(true);
        pushButton_decimal->setDefault(true);
        pushButton_s->setDefault(true);
        pushButton_div->setDefault(true);
        pushButton_15->setDefault(true);
        pushButton_potSquare->setDefault(true);
        pushButton_openParentesys->setDefault(true);
        pushButton_factorial->setDefault(true);
        pushButton_7->setDefault(true);
        pushButton_2->setDefault(true);
        pushButton_pi->setDefault(true);
        pushButton_5->setDefault(true);
        pushButton_del->setDefault(true);
        pushButton_sqrt->setDefault(true);
        pushButton->setDefault(true);
        pushButton_1->setDefault(true);
        pushButton_module->setDefault(true);
        pushButton_delAll->setDefault(true);
        pushButton_9->setDefault(true);
        pushButton_equal->setDefault(true);
        pushButton_closeParentesys->setDefault(true);
        pushButton_6->setDefault(true);
        pushButton_pot->setDefault(true);
        pushButton_nigga->setDefault(true);
        pushButton_4->setDefault(true);
        pushButton_anyRoot->setDefault(true);
        pushButton_add->setDefault(true);
        pushButton_mul->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        calcDisplay->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_sub->setText(QCoreApplication::translate("MainWindow", "-", "A nigga is a black person"));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "//", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_decimal->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_s->setText(QCoreApplication::translate("MainWindow", "NORMAL", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "\303\267", "A nigga is a black person"));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "//", nullptr));
        pushButton_potSquare->setText(QCoreApplication::translate("MainWindow", "x\302\262", nullptr));
        pushButton_openParentesys->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_factorial->setText(QCoreApplication::translate("MainWindow", "!", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_pi->setText(QCoreApplication::translate("MainWindow", "\317\200", "A nigga is a black person"));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_del->setText(QCoreApplication::translate("MainWindow", "DEL", "A nigga is a black person"));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "\302\262\342\210\232(x)", nullptr));
        pushButton->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton {\n"
"	background-color: rgb(0, 25, 130);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(0, 15, 110);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(0, 10, 100); \n"
"}", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "BACK", "A nigga is a black person"));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_module->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        pushButton_delAll->setText(QCoreApplication::translate("MainWindow", "AC", "A nigga is a black person"));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_equal->setText(QCoreApplication::translate("MainWindow", "=", "A nigga is a black person"));
        pushButton_closeParentesys->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_pot->setText(QCoreApplication::translate("MainWindow", "x\312\270", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_nigga->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Premilo a tuo rischio e pericolo</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_nigga->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Premilo a tuo rischio e pericolo.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_nigga->setText(QCoreApplication::translate("MainWindow", "HELP", "A nigga is a black person"));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_anyRoot->setText(QCoreApplication::translate("MainWindow", "\312\270\342\210\232(x)", nullptr));
        pushButton_add->setText(QCoreApplication::translate("MainWindow", "+", "A nigga is a black person"));
        pushButton_mul->setText(QCoreApplication::translate("MainWindow", "X", "A nigga is a black person"));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
