#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "simplex.h"

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

    void initDefTask();
    void initInterface();

    int controlVariablesCouner;
    int restrictionsCounter;

    QVector<double> C;
    QVector<double> B;
    QVector< QVector<double> > A;


private:
    Ui::MainWindow *ui;

private slots:
    void aboutQt();
    void about();

    void changeInputVarFielsd(int n);
    void changeInputResFielsd(int n);
};

#endif // MAINWINDOW_H
