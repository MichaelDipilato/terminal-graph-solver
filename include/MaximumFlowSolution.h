#ifndef MAXIMUMFLOWSOLUTION_H
#define MAXIMUMFLOWSOLUTION_H

#include <iostream>
#include <string>
#include <vector>
#include "ProblemSolver.h"
#include "ProblemSolution.h"

class MaximumFlowSolution : public ProblemSolution {
public:

    MaximumFlowSolution() = default;

    MaximumFlowSolution(std::string nm, std::string pr, int f, int gn, int gm, std::vector<std::vector<int>> fp) :
    name(nm), problem(pr), flow(f), n(gn), m(gm), flowPath(fp) {}

    std::ostream & output(std::ostream & os) const;

private:

    std::string name = "Please solve a problem before continuing!";

    std::string problem = "No problem selected";

    std::vector<std::vector<int>> flowPath;
    // Flow, number of vertices and edges
    int flow, n, m;

};

#endif
