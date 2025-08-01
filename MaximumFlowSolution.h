#ifndef MAXIMUMFLOWSOLUTION_H
#define MAXIMUMFLOWSOLUTION_H

#include <iostream>
#include <string>
#include "ProblemSolver.h"
#include "ProblemSolution.h"

class MaximumFlowSolution : public ProblemSolution {
public:

    MaximumFlowSolution() = default;

    MaximumFlowSolution(std::string nm, std::string pr, int f, int gn, int gm) :
    name(nm), problem(pr), flow(f), n(gn), m(gm) {}

    std::ostream & output(std::ostream & os) const;

private:

    std::string name = "Please solve a problem before continuing!";

    std::string problem = "No problem selected";
    // Flow, number of vertices and edges
    int flow, n, m;

};

#endif
