#ifndef SIMPLEX_H
#define SIMPLEX_H

#include <vector>
#include <iostream> //FIXME
#include <boost/multi_array.hpp>

namespace simplex
{

#define MIN 1
#define MAX 0

#define LESS -2
#define LESS_EQUAL -1
#define EQUAL 0
#define MORE_EQUAL 1
#define MORE 2

    //using namespace std;

    typedef boost::multi_array<double, 2> array2D;
    typedef array2D::index index;

    class Simplex
    {
    public:
        Simplex(int var, int res, double *C, double *B, double **A,bool min, char *EQ);
        void view();
        bool solve();
        bool isError(){return error;}
    protected:
        double M;
        int var;
        int res;
        bool min;
        int iteration;

        bool error;

        std::vector<double> C;
        std::vector<double> B;
        std::vector<char> EQ;
        array2D A;
        array2D::extent_gen extents;

        std::vector<int> Basis;
        std::vector<double> CBasis;
        std::vector<double> Teta;
        std::vector<double> Plan;
        std::vector<double> BasicPlan;  //Опорний план //Бугагашечки
        double result,resultPrev;



        void calculateM();
        void normalize();
        void makeBasis();
        bool isOptimal();

        int leaveBasis();
        int comeBasis();
        void calculateTeta(int divider);
        void calculateBasicPlan();
        void calculateResult();
        void makeNewSTable(int leave, int come);
    };

}

#endif // SIMPLEX_H
