#ifndef _REALIZATION_PROBLEM
#define _REALIZATION_PROBLEM

#include <fstream>
/*
 * Defining the realization problem of a matrix m*n
 *
 *
 */
class realizationProblem {
public:
    int m, n;
    int ** matrix;
    realizationProblem();
    realizationProblem(std::ifstream & _file);
    realizationProblem(int m,int n);
    void loadMatrixFromFile(std::ifstream & _file);
private:
    void initialize(int m, int n);
};


#endif