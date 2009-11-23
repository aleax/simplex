#include "simplex.h"

Simplex::Simplex(vector<double> C, vector<double> B, vector<double> A)
{
    this->A=A;
    this->B=B;
    this->C=C;
    calculateM();
}

void Simplex::calculateM()
{
    M=0.0;
    for (int i=0; i < (int) C.size(); ++i)
        if( M < C[i] )
            M=C[i];

}
