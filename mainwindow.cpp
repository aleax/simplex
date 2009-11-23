#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_about.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initDefTask();
    initInterface();
}

void MainWindow::initInterface()
{
    ui->inputControlVariables->setValue(controlVariablesCouner);
    ui->inputRestrictionsAmount->setValue(restrictionsCounter);
}

void MainWindow::initDefTask()
{
    controlVariablesCouner=3;
    restrictionsCounter=2;

    C.fill(0,controlVariablesCouner);
    B.fill(0,restrictionsCounter);
    A.resize(restrictionsCounter);
    A.fill(QVector<double>( controlVariablesCouner ) );
    C[0]=4;
    C[1]=3;
    C[2]=1;
    B[0]=2;
    B[1]=5;
    A[0][0]=4;
    A[0][1]=-3;
    A[0][2]=1;
    A[1][0]=1;
    A[1][1]=1;
    A[1][2]=1;
    qDebug()<<"Default initialization";
    qDebug()<<"C="<<C;
    qDebug()<<"B="<<B;
    qDebug()<<"A="<<A;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::aboutQt()
 {
     QApplication::aboutQt();
 }

void MainWindow::about()
{
    QDialog *form=new QDialog();
    Ui::About myui;
    myui.setupUi(form);

    form->show();
}

void MainWindow::targetFunction(QString f)
{
    this->tfparser.parse(f);
}

void MainWindow::changeInputCFielsd(int n)
{
    qDebug()<<"changeInputCFielsd"<<n;
    if (n>controlVariablesCouner)
        addInputCField(n);
    if (n<controlVariablesCouner)
        delInputCField(n);

}

void MainWindow::addInputCField(int n)
{
    qDebug()<<"add";
    QDoubleSpinBox a;
//    ui->InputCField->addWidget(
}

void MainWindow::delInputCField(int n)
{
    qDebug()<<"del";
}
