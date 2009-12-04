/*
#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}

*/
#include <iostream>
#include <vector>

#include "simplex.h"

using namespace std;
using namespace simplex;

int main()
{
    int var=3;
    int res=2;


    double **A,*B,*C;
    B=new double[res];
    C=new double[var];
    A=new double*[res];
    for(int i=0;i<res;++i)
        A[i]=new double[var];
    char *EQ=new char[res];
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
    EQ[0]=MORE_EQUAL;
    EQ[1]=LESS_EQUAL;

    bool min=true;
    Simplex simplex(var,res,C,B,A,min,EQ);
    //simplex.view(); //fixme
    simplex.solve();

  return 0;
}


