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

    //ui->tableWidgetC->set

    changeInputVarFielsd(controlVariablesCouner);
    changeInputResFielsd(restrictionsCounter);


}

void MainWindow::initDefTask()
{
    //init default demo task
    controlVariablesCouner=3;
    restrictionsCounter=2;

    C.fill(0,controlVariablesCouner);
    B.fill(0,restrictionsCounter);
    A.resize(restrictionsCounter);
    A.fill(QVector<double>( controlVariablesCouner ) );
    EQ.fill(EQUAL,restrictionsCounter);

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


void MainWindow::changeInputVarFielsd(int n)
{
    qDebug()<<"changeInputCFielsd"<<n;

    ui->tableWidgetC->setColumnCount(n);
    ui->tableWidgetC->resizeColumnsToContents();

    ui->tableWidgetA->setColumnCount(n);

    ui->tableWidgetA->resizeColumnsToContents();
    ui->tableWidgetB->resizeColumnsToContents();
    ui->tableWidgetEQ->resizeColumnsToContents();

    controlVariablesCouner=n;

}


void MainWindow::changeInputResFielsd(int n)
{
    qDebug()<<"changeInputResFielsd"<<n;

    ui->tableWidgetA->setRowCount(n);
    ui->tableWidgetB->setRowCount(n);
    ui->tableWidgetEQ->setRowCount(n);

    restrictionsCounter=n;
}

void MainWindow::solving()
{
    qDebug()<<"solving()";
    getData();

}

void MainWindow::getData()
{
    qDebug()<<"getData()";

    C.resize(controlVariablesCouner);
    B.resize(restrictionsCounter);
    EQ.resize(restrictionsCounter);
    A.resize(restrictionsCounter);
    for(int j=0; j<restrictionsCounter; ++j)
        A[j].resize(controlVariablesCouner);


    for (int i=0;i<controlVariablesCouner; ++i)
    {
        C[i]=ui->tableWidgetC->item(0,i)->text().toDouble();
        for(int j=0; j<restrictionsCounter; ++j)
        {
            B[j]=ui->tableWidgetB->item(j,0)->text().toDouble();
            EQ[j]=ui->tableWidgetEQ->item(j,0)->text().toAscii().constData()[0];
            A[i][j]=ui->tableWidgetA->item(i,j)->text().toDouble();
        }
    }
    qDebug()<<C;
    qDebug()<<B;
    qDebug()<<EQ;
    qDebug()<<A;
}
