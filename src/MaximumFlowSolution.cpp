#include <iostream>
#include <vector>
#include "ProblemSolution.h"
#include "MaximumFlowSolution.h"

using namespace std;

ostream & MaximumFlowSolution::output(ostream &os) const {

    os << "Problem solved: " << problem << endl;
    os << "Graph name: " << name << endl;
    os << "Total vertices: " << n << endl;
    os << "Total edges: " << m << endl;

    os << endl << "Maximum flow: " << flow << endl;

    os << endl << "Flow decomposition:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (flowPath[i][j] > 0) {
                os << i << '\t' << j
                   << '\t' << flowPath[i][j] << endl;
            }
        }
    }

    os << endl;
    return os;
}
