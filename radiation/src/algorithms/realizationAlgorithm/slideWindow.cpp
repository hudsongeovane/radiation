#ifndef _SLIDE_WINDOW_ALGORITHM
#define _SLIDE_WINDOW_ALGORITHM

#include "realizationAlgorithm.h"
#include "realizationProblem.h"


#include <algorithm>
using std::min;
using std::max;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

class slideWindowAlgorithm : public realizationAlgorithm {
private:
    vector<int> decreaseLine(vector<int> &line,int left, int right) {
        vector<int> result(line.size(),0);
        for(int i = left+1; i < right; i++) {
            line[i]--;
            result[i]++;
        }
        return result;
    }
public:
    slideWindowAlgorithm(realizationProblem * problem) {
        this->m = problem->m;
        this->n = problem->n;
        loadMatrix(problem->matrix);
    }
    vector< vector<int> > solveLine(vector<int> _line) {
        //The leafs go from left to the right.
        vector<int> line(_line);
        vector< vector<int> > lineSegments;
        
        if (line.empty()) {
            cout << "ERROR!" << endl;
            return lineSegments;
        }
        //One slide for each monitor-unit
        //const int maxSpeed = 1;
        
        //Check the starting position of the leaves. Look for a a(j) <= a(j-1)
        //This solution only works for maxSpeed==1
        
        int left = -1, right = 1;
        
        while (left < (int) line.size()-1) {
            //while (line[left+1] == 0) { left++; if (left == right) right++; }
            bool rightInc = false;
            if (line[left+1] == 0) {
                left++;
                if (left == right) { right++; rightInc=true; }
            }
            if (!rightInc && right <= (int) line.size()-1) if (line[right-1] < line[right]) right++;
            
            //while(line[right-1] < line[right]) right++;
            
            lineSegments.push_back(decreaseLine(line,left,right));
        }
        
        for(int i = 0; i < (int) lineSegments.size(); i++) {
            if (lineSegments[i].size() == 0) cout << "FUCK!" << endl;
        }
        return lineSegments;
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