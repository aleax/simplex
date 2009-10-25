/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Sun Oct 25 10:45:12 2009
**      by: Qt User Interface Compiler version 4.5.3
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
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
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
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QLineEdit *inputTargetFunction;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QComboBox *inputTaskType;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QLabel *label_4;
    QSpinBox *inputRestrictionsAmount;
    QLabel *label;
    QFrame *frame;
    QMenuBar *menuBar;
    QMenu *menuHello_World;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(552, 366);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionExit->setShortcutContext(Qt::ApplicationShortcut);
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridWidget = new QWidget(centralWidget);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setGeometry(QRect(10, 10, 531, 301));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        inputTargetFunction = new QLineEdit(gridWidget);
        inputTargetFunction->setObjectName(QString::fromUtf8("inputTargetFunction"));

        gridLayout->addWidget(inputTargetFunction, 1, 0, 1, 2);

        label_2 = new QLabel(gridWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 4, 1, 1);

        inputTaskType = new QComboBox(gridWidget);
        inputTaskType->setObjectName(QString::fromUtf8("inputTaskType"));

        gridLayout->addWidget(inputTaskType, 1, 3, 1, 1);

        label_3 = new QLabel(gridWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 1, 1, 1);

        label_4 = new QLabel(gridWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 3);

        inputRestrictionsAmount = new QSpinBox(gridWidget);
        inputRestrictionsAmount->setObjectName(QString::fromUtf8("inputRestrictionsAmount"));
        inputRestrictionsAmount->setValue(2);

        gridLayout->addWidget(inputRestrictionsAmount, 3, 3, 1, 1);

        label = new QLabel(gridWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 2);

        frame = new QFrame(gridWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame, 2, 4, 3, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 552, 23));
        menuHello_World = new QMenu(menuBar);
        menuHello_World->setObjectName(QString::fromUtf8("menuHello_World"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuHello_World->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuHello_World->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_Qt);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(activated()), MainWindow, SLOT(close()));
        QObject::connect(actionAbout_Qt, SIGNAL(activated()), MainWindow, SLOT(aboutQt()));
        QObject::connect(actionAbout, SIGNAL(activated()), MainWindow, SLOT(about()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "qSimplex", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        inputTargetFunction->setText(QApplication::translate("MainWindow", "4*x1+3*x2+x3", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\342\200\224>", 0, QApplication::UnicodeUTF8));
        inputTaskType->clear();
        inputTaskType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "min", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "max", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("MainWindow", "System of restrictions:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Restrictions amount", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Target Function:", 0, QApplication::UnicodeUTF8));
        menuHello_World->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
