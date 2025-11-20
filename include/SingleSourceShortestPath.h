#ifndef SINGLESOURCESHORTESTPATH_H
#define SINGLESOURCESHORTESTPATH_H

#include <vector>
#include "Graph.h"
#include "ProblemSolution.h"
#include "ProblemSolver.h"


class SingleSourceShortestPath : public ProblemSolver {
public:

    SingleSourceShortestPath() = default;

    ProblemSolution * solve(const Graph &);

private:

    int min_distance(std::vector<int>, std::vector<bool>, int);

};

#endif
