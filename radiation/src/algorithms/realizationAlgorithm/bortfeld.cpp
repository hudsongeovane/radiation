#ifndef _BORTFELD_ALGORITHM
#define _BORTFELD_ALGORITHM

#include "realizationAlgorithm.h"
#include "realizationProblem.h"

#include <iostream>
using std::cout;
using std::endl;

#include <set>
using std::set;

#include <algorithm>
using std::max;
using std::sort;
/*
 * Implementation of the Bortfeld algorithm. Sweep Technique.
 * 
 * T.R. Bortfeld, D.L. Kahler, T.J. Waldron, and A.L. Boyer, X–ray field compensation
 * with multileaf collimators, Int. J. Radiat. Oncol. Biol. Phys., 28, 723–730, 1994.
 */
 
class bortfeldAlgorithm : public realizationAlgorithm {
private:
    vector< vector<int> > solveLine(vector<int> _line) {
        vector<int> line;
        line.push_back(0);
        line.insert(line.begin()+1,_line.begin(),_line.end());
        line.push_back(0);

        vector<int> p, q;
        int L = 0;
        for(int k: line) {
            L = max(L,k);
        }
        for(int k = 1; k <= L; k++) {
            for(int i = 1; i <= (int) line.size(); i++) {
                if ((line[i-1] < k) && (k <= line[i])) p.push_back(i);
                if ((line[i] >= k) && (k > line[i+1])) q.push_back(i);
            }
        }
        
        //Make in Q the moves made on sorting P will change the technique to close-in
        sort(p.begin(),p.end());
        sort(q.begin(),q.end());
        
        vector< vector<int> > lineSegments;
        for(unsigned int i = 0; i < p.size(); i++) {
            vector<int> l(this->n,0);
            // k-1 due to the insertion of the 0s at beginning and the end of line
            for(int k = p[i]; k <= q[i]; k++) l[k-1]++;
            lineSegments.push_back(l);
            for(int k: l) {
                cout << k << " ";
            }
            cout << endl;

            
        }
        return lineSegments;
    }
public:
    bortfeldAlgorithm(realizationProblem * problem) {
        this->m = problem->m;
        this->n = problem->n;
        loadMatrix(problem->matrix);
    }
    void solve() {
        vector< vector< vector<int> > > lineSegments;
        int maxL = 0;
        for(int i = 0; i < this->m; i++) {
            lineSegments.push_back(solveLine(matrix[i]));
            maxL = max(maxL,(int) lineSegments.back().size());
        }
        
        for(int k = 0; k < maxL; k++) {
            vector< vector<int> > currentSegment;
            for(int i = 0; i < m; i++) {
                currentSegment.push_back(vector<int>(n,0));
            }
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    int tmp = 0;
                    if (k < (int) lineSegments[i].size()) {
                        tmp = lineSegments[i][k][j];
                    }
                    else tmp = 0;
                    currentSegment[i][j] = tmp;
                }
            }
            segments.push_back(currentSegment);
            coefficients.push_back(1);
        }
    }
};
    
#endif