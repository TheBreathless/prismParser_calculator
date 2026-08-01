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
    QLabel *calcDisplay;
    QVBoxLayout *verticalLayout_2;
    QLCDNumber *lcdNumberOld;
    QGridLayout *gridLayout;
    QPushButton *pushButton_8;
    QPushButton *pushButton_module;
    QPushButton *pushButton_div;
    QPushButton *pushButton_delAll;
    QPushButton *pushButton_7;
    QPushButton *pushButton_s;
    QPushButton *pushButton_0;
    QPushButton *pushButton_6;
    QPushButton *pushButton_decimal;
    QPushButton *pushButton_mul;
    QPushButton *pushButton_equal;
    QPushButton *pushButton_del;
    QPushButton *pushButton_pot;
    QPushButton *pushButton_1;
    QPushButton *pushButton_5;
    QPushButton *pushButton_9;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_sub;
    QPushButton *pushButton_4;
    QPushButton *pushButton_nigga;
    QPushButton *pushButton_add;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(325, 450);
        MainWindow->setMinimumSize(QSize(325, 450));
        QFont font;
        font.setFamilies({QString::fromUtf8("Cascadia Code")});
        font.setBold(true);
        MainWindow->setFont(font);
        MainWindow->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        MainWindow->setDockOptions(QMainWindow::DockOption::AllowTabbedDocks|QMainWindow::DockOption::AnimatedDocks);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        calcDisplay = new QLabel(centralwidget);
        calcDisplay->setObjectName("calcDisplay");
        calcDisplay->setMinimumSize(QSize(300, 75));
        calcDisplay->setMaximumSize(QSize(2000, 75));
        calcDisplay->setSizeIncrement(QSize(4, 1));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cascadia Code")});
        font1.setPointSize(25);
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

        verticalLayout_3->addWidget(calcDisplay);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(15);
        verticalLayout_2->setObjectName("verticalLayout_2");
        lcdNumberOld = new QLCDNumber(centralwidget);
        lcdNumberOld->setObjectName("lcdNumberOld");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(lcdNumberOld->sizePolicy().hasHeightForWidth());
        lcdNumberOld->setSizePolicy(sizePolicy);
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
        lcdNumberOld->setProperty("intValue", QVariant(271));

        verticalLayout_2->addWidget(lcdNumberOld);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(5);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(5, 0, 5, 0);
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy1);
        pushButton_8->setMinimumSize(QSize(50, 50));
        pushButton_8->setMaximumSize(QSize(16777215, 16777215));
        pushButton_8->setSizeIncrement(QSize(1, 1));
        pushButton_8->setBaseSize(QSize(50, 50));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Cascadia Code")});
        font3.setPointSize(12);
        font3.setBold(true);
        pushButton_8->setFont(font3);
        pushButton_8->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_8->setAutoFillBackground(false);
        pushButton_8->setIconSize(QSize(16, 16));
        pushButton_8->setCheckable(false);
        pushButton_8->setAutoRepeat(false);
        pushButton_8->setAutoDefault(false);
        pushButton_8->setFlat(false);

        gridLayout->addWidget(pushButton_8, 4, 1, 1, 1);

        pushButton_module = new QPushButton(centralwidget);
        pushButton_module->setObjectName("pushButton_module");
        pushButton_module->setEnabled(true);
        pushButton_module->setMinimumSize(QSize(50, 50));
        pushButton_module->setSizeIncrement(QSize(1, 1));
        pushButton_module->setBaseSize(QSize(50, 50));
        pushButton_module->setFont(font3);
        pushButton_module->setIconSize(QSize(16, 16));
        pushButton_module->setCheckable(false);

        gridLayout->addWidget(pushButton_module, 0, 3, 1, 1);

        pushButton_div = new QPushButton(centralwidget);
        pushButton_div->setObjectName("pushButton_div");
        pushButton_div->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_div->sizePolicy().hasHeightForWidth());
        pushButton_div->setSizePolicy(sizePolicy1);
        pushButton_div->setMinimumSize(QSize(50, 50));
        pushButton_div->setSizeIncrement(QSize(1, 1));
        pushButton_div->setBaseSize(QSize(50, 50));
        pushButton_div->setFont(font3);
        pushButton_div->setIconSize(QSize(16, 16));
        pushButton_div->setCheckable(false);
        pushButton_div->setAutoRepeat(false);
        pushButton_div->setAutoDefault(false);
        pushButton_div->setFlat(false);

        gridLayout->addWidget(pushButton_div, 1, 3, 1, 1);

        pushButton_delAll = new QPushButton(centralwidget);
        pushButton_delAll->setObjectName("pushButton_delAll");
        pushButton_delAll->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_delAll->sizePolicy().hasHeightForWidth());
        pushButton_delAll->setSizePolicy(sizePolicy1);
        pushButton_delAll->setMinimumSize(QSize(50, 50));
        pushButton_delAll->setSizeIncrement(QSize(1, 1));
        pushButton_delAll->setBaseSize(QSize(50, 50));
        pushButton_delAll->setFont(font3);
        pushButton_delAll->setCheckable(false);
        pushButton_delAll->setAutoRepeat(false);
        pushButton_delAll->setAutoDefault(false);
        pushButton_delAll->setFlat(false);

        gridLayout->addWidget(pushButton_delAll, 1, 1, 1, 1);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);
        pushButton_7->setMinimumSize(QSize(50, 50));
        pushButton_7->setMaximumSize(QSize(16777215, 16777215));
        pushButton_7->setSizeIncrement(QSize(1, 1));
        pushButton_7->setBaseSize(QSize(50, 50));
        pushButton_7->setFont(font3);
        pushButton_7->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_7->setAutoFillBackground(false);
        pushButton_7->setIconSize(QSize(16, 16));
        pushButton_7->setCheckable(false);
        pushButton_7->setAutoRepeat(false);
        pushButton_7->setAutoDefault(false);
        pushButton_7->setFlat(false);

        gridLayout->addWidget(pushButton_7, 4, 0, 1, 1);

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
        pushButton_s->setCheckable(true);
        pushButton_s->setChecked(false);
        pushButton_s->setAutoRepeat(false);
        pushButton_s->setAutoDefault(true);
        pushButton_s->setFlat(false);

        gridLayout->addWidget(pushButton_s, 5, 0, 1, 1);

        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName("pushButton_0");
        pushButton_0->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_0->sizePolicy().hasHeightForWidth());
        pushButton_0->setSizePolicy(sizePolicy1);
        pushButton_0->setMinimumSize(QSize(50, 50));
        pushButton_0->setMaximumSize(QSize(16777215, 16777215));
        pushButton_0->setSizeIncrement(QSize(1, 1));
        pushButton_0->setBaseSize(QSize(50, 50));
        pushButton_0->setFont(font3);
        pushButton_0->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_0->setAutoFillBackground(false);
        pushButton_0->setIconSize(QSize(16, 16));
        pushButton_0->setCheckable(false);
        pushButton_0->setAutoRepeat(false);
        pushButton_0->setAutoDefault(false);
        pushButton_0->setFlat(false);

        gridLayout->addWidget(pushButton_0, 5, 1, 1, 1);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setMinimumSize(QSize(50, 50));
        pushButton_6->setMaximumSize(QSize(16777215, 16777215));
        pushButton_6->setSizeIncrement(QSize(1, 1));
        pushButton_6->setBaseSize(QSize(50, 50));
        pushButton_6->setFont(font3);
        pushButton_6->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_6->setAutoFillBackground(false);
        pushButton_6->setIconSize(QSize(16, 16));
        pushButton_6->setCheckable(false);
        pushButton_6->setAutoRepeat(false);
        pushButton_6->setAutoDefault(false);
        pushButton_6->setFlat(false);

        gridLayout->addWidget(pushButton_6, 3, 2, 1, 1);

        pushButton_decimal = new QPushButton(centralwidget);
        pushButton_decimal->setObjectName("pushButton_decimal");
        pushButton_decimal->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_decimal->sizePolicy().hasHeightForWidth());
        pushButton_decimal->setSizePolicy(sizePolicy1);
        pushButton_decimal->setMinimumSize(QSize(50, 50));
        pushButton_decimal->setSizeIncrement(QSize(1, 1));
        pushButton_decimal->setBaseSize(QSize(50, 50));
        pushButton_decimal->setFont(font3);
        pushButton_decimal->setCheckable(false);
        pushButton_decimal->setAutoRepeat(false);
        pushButton_decimal->setAutoDefault(false);
        pushButton_decimal->setFlat(false);

        gridLayout->addWidget(pushButton_decimal, 5, 2, 1, 1);

        pushButton_mul = new QPushButton(centralwidget);
        pushButton_mul->setObjectName("pushButton_mul");
        pushButton_mul->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_mul->sizePolicy().hasHeightForWidth());
        pushButton_mul->setSizePolicy(sizePolicy1);
        pushButton_mul->setMinimumSize(QSize(50, 50));
        pushButton_mul->setSizeIncrement(QSize(1, 1));
        pushButton_mul->setBaseSize(QSize(50, 50));
        pushButton_mul->setFont(font3);
        pushButton_mul->setCheckable(false);
        pushButton_mul->setAutoRepeat(false);
        pushButton_mul->setAutoDefault(false);
        pushButton_mul->setFlat(false);

        gridLayout->addWidget(pushButton_mul, 4, 3, 1, 1);

        pushButton_equal = new QPushButton(centralwidget);
        pushButton_equal->setObjectName("pushButton_equal");
        pushButton_equal->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_equal->sizePolicy().hasHeightForWidth());
        pushButton_equal->setSizePolicy(sizePolicy1);
        pushButton_equal->setMinimumSize(QSize(50, 50));
        pushButton_equal->setSizeIncrement(QSize(1, 1));
        pushButton_equal->setBaseSize(QSize(50, 50));
        pushButton_equal->setFont(font3);
        pushButton_equal->setCheckable(false);
        pushButton_equal->setAutoRepeat(false);
        pushButton_equal->setAutoDefault(false);
        pushButton_equal->setFlat(false);

        gridLayout->addWidget(pushButton_equal, 5, 3, 1, 1);

        pushButton_del = new QPushButton(centralwidget);
        pushButton_del->setObjectName("pushButton_del");
        pushButton_del->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_del->sizePolicy().hasHeightForWidth());
        pushButton_del->setSizePolicy(sizePolicy1);
        pushButton_del->setMinimumSize(QSize(50, 50));
        pushButton_del->setSizeIncrement(QSize(1, 1));
        pushButton_del->setBaseSize(QSize(50, 50));
        pushButton_del->setFont(font3);
        pushButton_del->setCheckable(false);
        pushButton_del->setAutoRepeat(false);
        pushButton_del->setAutoDefault(false);
        pushButton_del->setFlat(false);

        gridLayout->addWidget(pushButton_del, 1, 2, 1, 1);

        pushButton_pot = new QPushButton(centralwidget);
        pushButton_pot->setObjectName("pushButton_pot");
        pushButton_pot->setEnabled(true);
        pushButton_pot->setMinimumSize(QSize(50, 50));
        pushButton_pot->setSizeIncrement(QSize(1, 1));
        pushButton_pot->setBaseSize(QSize(50, 50));
        pushButton_pot->setFont(font3);
        pushButton_pot->setIconSize(QSize(16, 16));
        pushButton_pot->setCheckable(false);
        pushButton_pot->setAutoDefault(false);
        pushButton_pot->setFlat(false);

        gridLayout->addWidget(pushButton_pot, 0, 2, 1, 1);

        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy1);
        pushButton_1->setMinimumSize(QSize(50, 50));
        pushButton_1->setMaximumSize(QSize(16777215, 16777215));
        pushButton_1->setSizeIncrement(QSize(1, 1));
        pushButton_1->setBaseSize(QSize(50, 50));
        pushButton_1->setFont(font3);
        pushButton_1->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_1->setAutoFillBackground(false);
        pushButton_1->setIconSize(QSize(16, 16));
        pushButton_1->setCheckable(false);
        pushButton_1->setAutoRepeat(false);
        pushButton_1->setAutoDefault(false);
        pushButton_1->setFlat(false);

        gridLayout->addWidget(pushButton_1, 2, 0, 1, 1);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);
        pushButton_5->setMinimumSize(QSize(50, 50));
        pushButton_5->setMaximumSize(QSize(16777215, 16777215));
        pushButton_5->setSizeIncrement(QSize(1, 1));
        pushButton_5->setBaseSize(QSize(50, 50));
        pushButton_5->setFont(font3);
        pushButton_5->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_5->setAutoFillBackground(false);
        pushButton_5->setIconSize(QSize(16, 16));
        pushButton_5->setCheckable(false);
        pushButton_5->setAutoRepeat(false);
        pushButton_5->setAutoDefault(false);
        pushButton_5->setFlat(false);

        gridLayout->addWidget(pushButton_5, 3, 1, 1, 1, Qt::AlignmentFlag::AlignVCenter);

        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy1);
        pushButton_9->setMinimumSize(QSize(50, 50));
        pushButton_9->setMaximumSize(QSize(16777215, 16777215));
        pushButton_9->setSizeIncrement(QSize(1, 1));
        pushButton_9->setBaseSize(QSize(50, 50));
        pushButton_9->setFont(font3);
        pushButton_9->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_9->setAutoFillBackground(false);
        pushButton_9->setIconSize(QSize(16, 16));
        pushButton_9->setCheckable(false);
        pushButton_9->setAutoRepeat(false);
        pushButton_9->setAutoDefault(false);
        pushButton_9->setFlat(false);

        gridLayout->addWidget(pushButton_9, 4, 2, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setMinimumSize(QSize(50, 50));
        pushButton_2->setMaximumSize(QSize(16777215, 16777215));
        pushButton_2->setSizeIncrement(QSize(1, 1));
        pushButton_2->setBaseSize(QSize(50, 50));
        pushButton_2->setFont(font3);
        pushButton_2->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_2->setAutoFillBackground(false);
        pushButton_2->setIconSize(QSize(16, 16));
        pushButton_2->setCheckable(false);
        pushButton_2->setAutoRepeat(false);
        pushButton_2->setAutoDefault(false);
        pushButton_2->setFlat(false);

        gridLayout->addWidget(pushButton_2, 2, 1, 1, 1);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setMinimumSize(QSize(50, 50));
        pushButton_3->setMaximumSize(QSize(16777215, 16777215));
        pushButton_3->setSizeIncrement(QSize(1, 1));
        pushButton_3->setBaseSize(QSize(50, 50));
        pushButton_3->setFont(font3);
        pushButton_3->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_3->setAutoFillBackground(false);
        pushButton_3->setIconSize(QSize(16, 16));
        pushButton_3->setCheckable(false);
        pushButton_3->setAutoRepeat(false);
        pushButton_3->setAutoDefault(false);
        pushButton_3->setFlat(false);

        gridLayout->addWidget(pushButton_3, 2, 2, 1, 1);

        pushButton_sub = new QPushButton(centralwidget);
        pushButton_sub->setObjectName("pushButton_sub");
        pushButton_sub->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_sub->sizePolicy().hasHeightForWidth());
        pushButton_sub->setSizePolicy(sizePolicy1);
        pushButton_sub->setMinimumSize(QSize(50, 50));
        pushButton_sub->setSizeIncrement(QSize(1, 1));
        pushButton_sub->setBaseSize(QSize(50, 50));
        pushButton_sub->setFont(font3);
        pushButton_sub->setCheckable(false);
        pushButton_sub->setAutoRepeat(false);
        pushButton_sub->setAutoDefault(false);
        pushButton_sub->setFlat(false);

        gridLayout->addWidget(pushButton_sub, 3, 3, 1, 1);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setMinimumSize(QSize(50, 50));
        pushButton_4->setMaximumSize(QSize(16777215, 16777215));
        pushButton_4->setSizeIncrement(QSize(1, 1));
        pushButton_4->setBaseSize(QSize(50, 50));
        pushButton_4->setFont(font3);
        pushButton_4->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_4->setAutoFillBackground(false);
        pushButton_4->setIconSize(QSize(16, 16));
        pushButton_4->setCheckable(false);
        pushButton_4->setAutoRepeat(false);
        pushButton_4->setAutoDefault(false);
        pushButton_4->setFlat(false);

        gridLayout->addWidget(pushButton_4, 3, 0, 1, 1);

        pushButton_nigga = new QPushButton(centralwidget);
        pushButton_nigga->setObjectName("pushButton_nigga");
        pushButton_nigga->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_nigga->sizePolicy().hasHeightForWidth());
        pushButton_nigga->setSizePolicy(sizePolicy1);
        pushButton_nigga->setMinimumSize(QSize(50, 50));
        pushButton_nigga->setSizeIncrement(QSize(1, 1));
        pushButton_nigga->setBaseSize(QSize(50, 50));
        pushButton_nigga->setFont(font3);
        pushButton_nigga->setToolTipDuration(15);
        pushButton_nigga->setCheckable(false);
        pushButton_nigga->setAutoRepeat(false);
        pushButton_nigga->setAutoDefault(false);
        pushButton_nigga->setFlat(false);

        gridLayout->addWidget(pushButton_nigga, 1, 0, 1, 1);

        pushButton_add = new QPushButton(centralwidget);
        pushButton_add->setObjectName("pushButton_add");
        pushButton_add->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_add->sizePolicy().hasHeightForWidth());
        pushButton_add->setSizePolicy(sizePolicy1);
        pushButton_add->setMinimumSize(QSize(50, 50));
        pushButton_add->setMaximumSize(QSize(16777215, 16777215));
        pushButton_add->setSizeIncrement(QSize(1, 1));
        pushButton_add->setBaseSize(QSize(50, 50));
        pushButton_add->setFont(font3);
        pushButton_add->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton_add->setAutoFillBackground(false);
        pushButton_add->setIconSize(QSize(16, 16));
        pushButton_add->setCheckable(false);
        pushButton_add->setAutoRepeat(false);
        pushButton_add->setAutoDefault(false);
        pushButton_add->setFlat(false);

        gridLayout->addWidget(pushButton_add, 2, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        pushButton_8->setDefault(true);
        pushButton_module->setDefault(true);
        pushButton_div->setDefault(true);
        pushButton_delAll->setDefault(true);
        pushButton_7->setDefault(true);
        pushButton_s->setDefault(true);
        pushButton_0->setDefault(true);
        pushButton_6->setDefault(true);
        pushButton_decimal->setDefault(true);
        pushButton_mul->setDefault(true);
        pushButton_equal->setDefault(true);
        pushButton_del->setDefault(true);
        pushButton_pot->setDefault(true);
        pushButton_1->setDefault(true);
        pushButton_5->setDefault(true);
        pushButton_9->setDefault(true);
        pushButton_2->setDefault(true);
        pushButton_3->setDefault(true);
        pushButton_sub->setDefault(true);
        pushButton_4->setDefault(true);
        pushButton_nigga->setDefault(true);
        pushButton_add->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        calcDisplay->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_module->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_delAll->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_s->setText(QCoreApplication::translate("MainWindow", "ADV", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_decimal->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_mul->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        pushButton_equal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_del->setText(QCoreApplication::translate("MainWindow", "DEL", nullptr));
        pushButton_pot->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_sub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_nigga->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Premilo a tuo rischio e pericolo</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_nigga->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Premilo a tuo rischio e pericolo.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_nigga->setText(QCoreApplication::translate("MainWindow", "?", "A nigga is a black person"));
        pushButton_add->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
