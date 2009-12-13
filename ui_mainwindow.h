/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Sat Dec 12 16:15:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionAbout_Qt;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_2;
    QComboBox *inputTaskType;
    QSpinBox *inputRestrictionsAmount;
    QSpinBox *inputControlVariables;
    QLabel *label_5;
    QWidget *inputCField;
    QHBoxLayout *InputCField;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(285, 290);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionExit->setShortcutContext(Qt::ApplicationShortcut);
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setMargin(11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridWidget = new QWidget(centralWidget);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(gridWidget->sizePolicy().hasHeightForWidth());
        gridWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(gridWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 4, 0, 1, 2);

        label_4 = new QLabel(gridWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        label = new QLabel(gridWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Plain);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        label_2 = new QLabel(gridWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        inputTaskType = new QComboBox(gridWidget);
        inputTaskType->setObjectName(QString::fromUtf8("inputTaskType"));

        gridLayout->addWidget(inputTaskType, 1, 1, 1, 1);

        inputRestrictionsAmount = new QSpinBox(gridWidget);
        inputRestrictionsAmount->setObjectName(QString::fromUtf8("inputRestrictionsAmount"));
        inputRestrictionsAmount->setMinimum(1);
        inputRestrictionsAmount->setMaximum(100);
        inputRestrictionsAmount->setValue(2);

        gridLayout->addWidget(inputRestrictionsAmount, 5, 1, 1, 1);

        inputControlVariables = new QSpinBox(gridWidget);
        inputControlVariables->setObjectName(QString::fromUtf8("inputControlVariables"));
        inputControlVariables->setMinimum(1);
        inputControlVariables->setValue(3);

        gridLayout->addWidget(inputControlVariables, 2, 1, 1, 1);

        label_5 = new QLabel(gridWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        inputCField = new QWidget(gridWidget);
        inputCField->setObjectName(QString::fromUtf8("inputCField"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(10);
        sizePolicy1.setHeightForWidth(inputCField->sizePolicy().hasHeightForWidth());
        inputCField->setSizePolicy(sizePolicy1);
        InputCField = new QHBoxLayout(inputCField);
        InputCField->setSpacing(6);
        InputCField->setMargin(11);
        InputCField->setObjectName(QString::fromUtf8("InputCField"));

        gridLayout->addWidget(inputCField, 3, 0, 1, 2);


        gridLayout_2->addWidget(gridWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 285, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        label_4->setBuddy(inputRestrictionsAmount);
        label_2->setBuddy(inputTaskType);
        label_5->setBuddy(inputControlVariables);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(inputTaskType, inputControlVariables);
        QWidget::setTabOrder(inputControlVariables, inputRestrictionsAmount);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_Qt);
        mainToolBar->addAction(actionExit);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(activated()), MainWindow, SLOT(close()));
        QObject::connect(actionAbout_Qt, SIGNAL(activated()), MainWindow, SLOT(aboutQt()));
        QObject::connect(actionAbout, SIGNAL(activated()), MainWindow, SLOT(about()));
        QObject::connect(inputControlVariables, SIGNAL(valueChanged(int)), MainWindow, SLOT(changeInputCFielsd(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "qSimplex", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "System of Restrictions", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Namber of Restrictions", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Target Function", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Task type", 0, QApplication::UnicodeUTF8));
        inputTaskType->clear();
        inputTaskType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "min", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "max", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("MainWindow", "Namber of Control variables", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
