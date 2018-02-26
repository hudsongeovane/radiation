#ifndef _REALIZATION_ALGORITHM
#define _REALIZATION_ALGORITHM

#include <vector>
using std::vector;

class realizationAlgorithm {
public:
    vector<int> coefficients;
    vector<int**> segments;
    int ** matrix;
    int m, n;
    virtual void solve() = 0;
    void loadMatrix(int ** m) {
        matrix = m;
    }
};

#endif