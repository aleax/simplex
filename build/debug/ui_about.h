/********************************************************************************
** Form generated from reading ui file 'about.ui'
**
** Created: Sun Oct 18 18:15:20 2009
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
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QFrame *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QString::fromUtf8("About"));
        About->setWindowModality(Qt::NonModal);
        About->resize(391, 217);
        About->setMinimumSize(QSize(387, 202));
        About->setFrameShape(QFrame::StyledPanel);
        About->setFrameShadow(QFrame::Raised);
        textBrowser = new QTextBrowser(About);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 371, 151));
        pushButton = new QPushButton(About);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 170, 89, 25));

        retranslateUi(About);
        QObject::connect(pushButton, SIGNAL(clicked()), About, SLOT(close()));

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QFrame *About)
    {
        About->setWindowTitle(QApplication::translate("About", "About", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("About", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'DejaVu Sans'; font-size:14pt;\">\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\203 \321\200\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\260\320\273 \321\201\321\202\321\203\320\264\320\265\320\275\321\202 \320\263\321\203\320\277\320\277\321\213 1\320\241I-07 \320\221\320\276\320\275\320\264\320\260\321\200\321\207\321\203\320\272 \320\220\320\273\320\265\320\272\321\201\320\265\320\271 \320\222\320\260\320\273\320\265\321\200\321\214\320\265\320\262\320\270\321\207, \320\275\320\276 \320\276\320"
                        "\275\320\260 \320\277\320\276\320\272\320\260 \320\265\321\211\320\265 \320\275\320\270\321\207\320\265\320\263\320\276 \320\277\320\276\320\273\320\265\320\267\320\275\320\276\320\263\320\276 \320\275\320\265 \320\264\320\265\320\273\320\260\320\265\321\202.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'DejaVu Sans'; font-size:14pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'DejaVu Sans'; font-size:14pt;\">=)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("About", "\320\236\320\272\320\265\321\216\321\210\320\272\320\270", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(About);
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
