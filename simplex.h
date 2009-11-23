#ifndef SIMPLEX_H
#define SIMPLEX_H

#include <vector>
#include <algorithm>

using namespace std;

class Simplex
{
public:
    Simplex(vector<double> C, vector<double> B, vector<double> A);
protected:
    double M;
    void calculateM();
    vector<double> C;
    vector<double> B;
    vector<double> A;
};

#endif // SIMPLEX_H
