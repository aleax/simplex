#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "tfparser.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);
    TFParser tfparser;

private:
    Ui::MainWindow *ui;

private slots:
    void aboutQt();
    void about();
    void targetFunction(QString f);
};

#endif // MAINWINDOW_H
