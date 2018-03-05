#ifndef _SLIDE_WINDOW_ALGORITHM
#define _SLIDE_WINDOW_ALGORITHM

#include <vector>
using std::vector;

class slideWindowAlgorithm : public realizationAlgorithm {
public:
    slideWindowAlgorithm(realizationProblem * problem) {
        this->m = problem->m;
        this->n = problem->n;
        loadMatrix(problem->matrix);
    }
    void solveLine(vector<int> line) {
        if (line.empty()) return;
        
        //The leafs go from left to the right.
        //I-th element of each vector indicates where is each leaf at time I
        vector<int> rightLeaf, leftLeaf;
        
        //One slide for each monitor-unit
        const int maxSpeed = 1;
        
        //Check the starting position of the leaves. Look for a a(j) <= a(j)-1
        
    }
};

#endif