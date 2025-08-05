#ifndef ALLPAIRSSHORTESTPATH_H
#define ALLPAIRSSHORTESTPATH_H

#include <vector>
#include "Graph.h"
#include "ProblemSolution.h"
#include "ProblemSolver.h"


class AllPairsShortestPath : public ProblemSolver {
public:

    AllPairsShortestPath() = default;

    ProblemSolution * solve(const Graph &);
};

#endif
