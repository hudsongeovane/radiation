#include "realizationProblem.h"

//matrix is an array of lines
realizationProblem::realizationProblem(int m, int n) {
    initialize(m,n);
    
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            this->matrix[i][j] = 0;
}
void realizationProblem::initialize(int m, int n) {
    if (matrix != NULL) {
        //I have to use this->m here because m and n are the new values of the matrix.
        for(int i = 0; i < this->m; i++)
            delete matrix[i];
        delete[] matrix;
    }
    
    this->n = n; this->m = m;
    this->matrix = new int*[n];
    for(int i = 0; i < n; ++i) this->matrix[i] = new int[m];
}
void realizationProblem::loadMatrixFromFile(std::ifstream & _file) {
    int m,n;
    _file >> m >> n;
    
    /*
     * First I call initialize() to delete[] the matrix with the current m and n. Not with
     * the new.
     * 
     * And then I update this->m and this->n with the new m and n.
     */
    initialize(m,n);
    
    this->m = m;
    this->n = n;
    
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j) {
            int tmp = 1;
            _file >> tmp;
            this->matrix[i][j] = tmp;
        }
}

realizationProblem::realizationProblem() {
    return;
}