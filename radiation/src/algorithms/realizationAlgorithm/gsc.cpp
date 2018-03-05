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
public:
    gscAlgorithm(realizationProblem * problem) {
        this->m = problem->m;
        this->n = problem->n;
        loadMatrix(problem->matrix);
    }
    void solve() {
        vector< vector<int> > A(m,vector<int>(n,0));
        vector< vector<int> > TEMP(m,vector<int>(n,0));
        
        
        int u = 9999999, L = -1;
        for(int i = 0; i < this->m; ++i) {
            for(int j = 0; j < this->n; ++j) {
                A[i][j] = matrix[i][j];
                u = min(u,matrix[i][j]);
                L = max(L,matrix[i][j]);
            }
        }
        /*
         * Part 1:
         * Removing background intensity.
         * the lower value in the matrix will define the first segment.
         */
        for(int i = 0; i < this->m; ++i) {
            for(int j = 0; j < this->n; ++j) {
                A[i][j] -= u;
            }
        }
        coefficients.push_back(u);
        vector< vector<int> > segment1(m,vector<int>(n,0));
        for(int a = 0; a < m; ++a) {
            for(int b = 0; b < n; ++b) {
                segment1[a][b] = 1;
            }
        }
        segments.push_back(segment1);
    
        /* Part two:
         * Iterating until A is empty.
         */
        double uu = 0;
        while (((uu/2) * (uu+1)) < L) uu += 1.;
        u = (int) uu;
        bool aequalzero=false;
 
        
        vector< vector< vector<int> > > _segments;
        vector<int> _coefficients;
        vector< pair< int, pair<int,int> > > intervals;
        
        do {
            _segments.clear();
            _coefficients.clear();
            
            
            for(int i = 0; i<m; i++)
                for(int j = 0; j < n; j++)
                    TEMP[i][j]=0;
                    
            
            /*
             * Set of intervals.
             * pair < intLine, pair <intL, intR> >
             * On line intLine there are intervals from intL to intR
             */
            intervals.clear();
            
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
            //printing matrix A
            /*for(int i = 0; i < m; ++i) {
                for(int k = 0; k < n; ++k) {
                    cout << A[i][k];
                    if (k+1 != n) cout << "\t";
                    else cout << endl;
                }
            }*/
             
                int total_segments = 0;

                vector<int> vetor(m,0);

                for(unsigned int i = 0; i < intervals.size(); i++) {
                    int k = intervals.at(i).first;
                    vetor[k]++;
                    
                }
                for(int i = 0; i < m; i++) {
                    total_segments = max(total_segments,vetor[i]);
                }
        
            //Adding empty segments to the vector of segments.
            for(int i = 0; i<total_segments; i++) {
                _coefficients.push_back(u);
                vector< vector<int> > segment(m,vector<int>(n,0));
                
                for(int a = 0; a < m; ++a) {
                    for(int b = 0; b < n; ++b) {
                        segment[a][b] = 0;
                    }
                }
                _segments.push_back(segment);
            }

            /*
             * Now its time to create the segments for this iteration.
             * Coefficients are already set up.
             */
            vector<int> added(intervals.size(),0); //mark which intervals were used already
            for(int s = 0; s < total_segments; s++) {
                set<int> used_lines;
                used_lines.clear();
                for(unsigned int i = 0; i < intervals.size(); i++) {
                    if((added[i] == 0) && (used_lines.find(intervals[i].first) == used_lines.end())) {
                        //filling the intervals on the segments
                        //from left to right
                        for(int z = intervals[i].second.first; z<=intervals[i].second.second; z++)
                            _segments[s][intervals[i].first][z] = 1;
                        
                        //for not adding this intervall anymore
                        added[i] = 1;
                        
                        //for not filling another interval from this line on this segment
                        used_lines.insert(intervals[i].first);
                    }
                }
            }
            
            aequalzero=true;
            
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    if (TEMP[i][j] > 0) A[i][j] -= u;
                    if (A[i][j] != 0) aequalzero = false;
                }
            }
            
            u--;
            
            /*
             * Adding segments and coeffiecients to the real vectors.
             * 
             * The next iteration will start with empty _segments and _coefficients
             */
            for(vector< vector<int> > v : _segments) {
                segments.push_back(v);
            }
            for(int v : _coefficients) {
                coefficients.push_back(v);
            }
            
        } while (!aequalzero);
        
        cout << segments.size() << " segments" << endl;
        
    }
};

#endif