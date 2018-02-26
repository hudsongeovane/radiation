#include "realizationAlgorithm.h"
#include "realizationProblem.h"


/*
 * Implementation of the Galvin, Chen and Smith algorithm.
 * 
 * J.M. Galvin, X.G. Chen, and R.M. Smith, Combining multileaf fields to modulate
 * fluence distributions, Int. J. Radiat. Oncol. Biol. Phys., 27, 697–705, 1993.
 */
int min(int a, int b) {
    if (a<b) return a;
    return b;
}
int max(int a, int b) {
    if (a>b) return a;
    return b;
}

class gscAlgorithm : public realizationAlgorithm {
public:
    gscAlgorithm(realizationProblem * problem) {
        this->matrix = problem->matrix;
        this->m = problem->m;
        this->n = problem->n;
    }
    void solve() {
        int ** A = new int*[n];
        int u = 9999999, L = -1;
        for(int i = 0; i < this->n; ++i) {
            A[i] = new int[m];
            for(int j = 0; j < m; ++j) {
                A[i][j] = matrix[i][j];
                u = min(u,matrix[i][j]);
                L = max(L,matrix[i][j]);
            }
        }
        
        for(int i = 0; i < this->m; ++i) {
            for(int j = 0; j < this->n; ++j) {
                A[i][j] -= u;
            }
        }
        u = 0;
        while (((u/2) * (u+1)) < L) u++;
        
        
    }
};