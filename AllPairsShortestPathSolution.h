#ifndef ALLPAIRSSHORTESTPATHSOLUTION_H
#define ALLPAIRSSHORTESTPATHSOLUTION_H

#include <iostream>
#include <string>
#include "ProblemSolver.h"
#include "ProblemSolution.h"

class AllPairsShortestPathSolution : public ProblemSolution {
public:

    AllPairsShortestPathSolution() = default;

    AllPairsShortestPathSolution(std::string nm, std::string pr, std::vector<int> p, std::vector<int> c, int gn, int gm) :
    name(nm), problem(pr), path(p), cost(c), n(gn), m(gm) {}

    std::ostream & output(std::ostream & os) const;

private:

    std::string name = "Please solve a problem before continuing!";

    std::string problem = "No problem selected";

    std::vector<int> path;

    std::vector<int> cost;
    // Number of vertices and edges
    int n, m;

};

#endif
