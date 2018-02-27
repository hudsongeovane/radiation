#ifndef _REALIZATION_ALGORITHM
#define _REALIZATION_ALGORITHM

#include <vector>
#include <fstream>

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
    void printToFile(std::ofstream & _file) {
        for(int k: coefficients) {
            _file << k << "*\t|";
            for(unsigned int s = 0; s < segments.size(); s++) {
                for(int i = 0; i < n; i++)
                    _file << segments[s][0][i] << "\t";
                _file << "|\t";
            }
        }
        _file << "\n";
        /*for(int k: coefficients) {
            for(int line = 1; line < m; line++) {
                _file << "\t|";
                for(unsigned int s = 0; s < segments.size(); s++) {
                    for(int i = 0; i < n; i++)
                        _file << segments[s][line][i] << "\t";
                    _file << "|\t";
                }
            }
            _file << "\n";
        }*/
    }
};

#endif