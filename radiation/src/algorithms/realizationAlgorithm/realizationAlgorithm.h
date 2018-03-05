#ifndef _REALIZATION_ALGORITHM
#define _REALIZATION_ALGORITHM

#include <vector>
#include <fstream>
#include <memory>

using std::vector;

class realizationAlgorithm {
public:
    vector<int> coefficients;
    vector< vector< vector <int> > > segments;
    vector< vector <int> > matrix;
    int m, n;
    virtual void solve() = 0;
    void loadMatrix(int ** mm) {
        for(int i = 0; i < m; i++) {
            matrix.push_back(vector<int>(n,0));
            for(int j = 0; j < n; j++){
                matrix[i][j] = mm[i][j];
            }
        }
    }
    void printToFile(std::ofstream & _file) {
        for(int lines = 0; lines < m; lines++) {
            for(unsigned int i = 0; i < coefficients.size(); i++) {
                if (lines == m/2) _file << coefficients[i] << "*\t|\t";
                else _file << "\t|\t";
                for(int j = 0; j < n; j++) {
                    _file << segments[i][lines][j] << "\t";
                }
                _file << "|\t";
            }
            _file << "\n";
        }
    }
    bool checkResult() {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int soma = 0;
                for(unsigned int s = 0; s < segments.size(); s++) {
                    soma += coefficients[s] * segments[s][i][j];
                }
                if (soma != matrix[i][j]) return false;
            }
        }
        return true;
    }
};

#endif