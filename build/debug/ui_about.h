/********************************************************************************
** Form generated from reading ui file 'about.ui'
**
** Created: Sun Oct 18 19:28:19 2009
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QFrame *gridFrame;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QTextBrowser *textBrowser;

    void setupUi(QFrame *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QString::fromUtf8("About"));
        About->setWindowModality(Qt::NonModal);
        About->setEnabled(true);
        About->resize(463, 322);
        About->setMinimumSize(QSize(0, 0));
        About->setAutoFillBackground(false);
        About->setFrameShape(QFrame::StyledPanel);
        About->setFrameShadow(QFrame::Raised);
        gridFrame = new QFrame(About);
        gridFrame->setObjectName(QString::fromUtf8("gridFrame"));
        gridFrame->setGeometry(QRect(0, 0, 461, 321));
        gridLayout = new QGridLayout(gridFrame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(gridFrame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        textBrowser = new QTextBrowser(gridFrame);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout->addWidget(textBrowser, 1, 0, 1, 2);


        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QFrame *About)
    {
        About->setWindowTitle(QApplication::translate("About", "About", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("About", "Close", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("About", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\203 \321\200\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\260\320\273 \321\201\321\202\321\203\320\264\320\265\320\275 \320\263\321\200\321\203\320\277\321\213 1\320\241\320\206-07</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\221\320\276\320\275\320\264\320\260\321\200\321\207\321\203\320\272 \320\220\320\273\320\265\320\272\321\201\320\265\320\271</p></body></html>", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(About);
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
