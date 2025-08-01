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

    os << endl;
    return os;
}
