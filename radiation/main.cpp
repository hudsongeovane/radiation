#include <iostream>
#include <fstream>
#include "realizationProblem.h"
#include "/home/hudson/Documentos/radiation/radiation/src/algorithms/realizationAlgorithm/gsc.cpp"

//TODO: Implement destructors.

using std::cout;
using std::cin;
using std::endl;

void printMatrix(realizationProblem * problem) {
    for(int i = 0; i < problem->m; ++i)
        for(int j = 0; j < problem->n; ++j) {
            cout << problem->matrix[i][j];
            if (j+1 != problem->n) cout << "\t";
            else cout << endl;
        }
            
}

int main(int argc, char **argv)
{
	realizationProblem * problem = new realizationProblem();
    
    std::ifstream testdata1;
    testdata1.open("../testData/testdata2.dat", std::ifstream::in);
    
    std::ofstream _file("../outputFile.txt",std::ofstream::out);
    
    if (testdata1.is_open()) {
        problem->loadMatrixFromFile(testdata1);
    }
    printMatrix(problem);
    
    realizationAlgorithm * t = new gscAlgorithm(problem);
    t->solve();
    
    t->printToFile(_file);
    if(t->checkResult()) cout << "It worked!" << endl;
    _file.close();
    
    delete problem;
	return 0;
}
