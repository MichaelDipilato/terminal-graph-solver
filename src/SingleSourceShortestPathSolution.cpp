#include <iostream>
#include <vector>
#include "ProblemSolution.h"
#include "SingleSourceShortestPathSolution.h"

using namespace std;

ostream & SingleSourceShortestPathSolution::output(ostream &os) const {

    os << "Problem solved: " << problem << endl;
    os << "Graph name: " << name << endl;
    os << "Total vertices: " << n << endl;
    os << "Total edges: " << m << endl;

    for (decltype(path.size()) i = 0; i < path.size(); i++) {
        os << path[i];
        if (i % 2 != 0 && i != 0) {
            os << '\t' << cost[i/2];
            os << endl;
        } else {
            os << "\t";
        }
    }

    os << endl;
    return os;
}
