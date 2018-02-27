#ifndef _GSC_ALGORITHM
#define _GSC_ALGORITHM

#include "realizationAlgorithm.h"
#include "realizationProblem.h"

#include <utility>
#include <set>
#include <queue>
#include <iostream>
#include <algorithm>

using std::set;
using std::pair;
using std::make_pair;
using std::min;
using std::max;
using std::queue;

using std::cout;
using std::endl;
/*
 * Implementation of the Galvin, Chen and Smith algorithm.
 * 
 * J.M. Galvin, X.G. Chen, and R.M. Smith, Combining multileaf fields to modulate
 * fluence distributions, Int. J. Radiat. Oncol. Biol. Phys., 27, 697–705, 1993.
 */

class gscAlgorithm : public realizationAlgorithm {
    void fillSegmentWithInterval(int s, int line, int l, int r) {
        for(int i = l; i<=r; i++)
            segments[s][line][i] = 1;
    }
public:
    gscAlgorithm(realizationProblem * problem) {
        this->matrix = problem->matrix;
        this->m = problem->m;
        this->n = problem->n;
    }
    void solve() {
        int A[m][n];
        int u = 9999999, L = -1;
        for(int i = 0; i < this->m; ++i) {
            for(int j = 0; j < this->n; ++j) {
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
        
        double uu = 0;
        while (((uu/2) * (uu+1)) < L) uu++;
        u = (int) uu;
        std::cout << "Valor de u:" << uu << std::endl;
        
        int TEMP[m][n];
        
        /*
         * Set of intervals.
         * pair < intLine, pair <intL, intR> >
         * On line intLine there are intervals from intL to intR
         */
        vector< pair< int, pair<int,int> > > intervals; 
        
        for(int i = 0; i < this->m; ++i) {
            for(int j = 0; j < this->n; ++j) {
                if (A[i][j] >= u) {
                    TEMP[i][j] = 1;
                    if (!intervals.empty()) {
                        if (intervals.back().first == i && intervals.back().second.second == j-1) {
                            pair< int, pair<int,int> > tmp = make_pair(i,make_pair(intervals.back().second.first,j));
                            intervals.pop_back();
                            intervals.push_back(tmp);
                        }
                        else intervals.push_back(make_pair(i,make_pair(j,j)));
                    }
                    else intervals.push_back(make_pair(i,make_pair(j,j)));
                }
                else TEMP[i][j] = 0;
            }
        }
        int total_segments = 0;
        int v[intervals.size()] = { };
        for(unsigned int i = 0; i < intervals.size(); i++) {
            //std::cout << x.first << " " << x.second.first << " " << x.second.second << std::endl;
            v[intervals[i].first]++;
            total_segments = max(total_segments,v[intervals[i].first]);
        }
        

        for(int i = 0; i<total_segments; i++) {
            coefficients.push_back(u);
            
            int ** segment = new int*[n];
            for(int j = 0; j < n; ++j) segment[j] = new int[m];
            
            for(int a = 0; a < m; ++a) {
                for(int b = 0; b < n; ++b) {
                    segment[a][b] = 0;
                }
            }
            segments.push_back(segment);
        }
        
        /*
         * Now its time to create the segments for this iteration.
         * Coefficients are already set up.
         */
        int added[intervals.size()] = { }; //mark which intervals were used already
        for(int s = 0; s < total_segments; s++) {
            set<int> used_lines;
            used_lines.clear();
            for(unsigned int i = 0; i < intervals.size(); i++) {
                if((added[i] == 0) && (used_lines.find(intervals[i].first) == used_lines.end())) {
                    fillSegmentWithInterval(s,intervals[i].first,intervals[i].second.first,intervals[i].second.second);
                    added[i] = 1;
                    used_lines.insert(intervals[i].first);
                }
            }
        }
        
        
        for(int i = 0; i < this->m; ++i) {
            for(int j = 0; j < this->n; ++j) {
                if (TEMP[i][j]) A[i][j] -= u;
            }
        }
        
        for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j) {
            cout << A[i][j];
            if (j+1 != n) cout << "\t";
            else cout << endl;
        }
        
    }
};

#endif