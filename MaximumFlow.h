#ifndef MAXIMUMFLOW_H
#define MAXIMUMFLOW_H

#include <vector>
#include "Graph.h"
#include "ProblemSolution.h"
#include "ProblemSolver.h"

class MaximumFlow : public ProblemSolver {
public:

    MaximumFlow() = default;

    ProblemSolution * solve(const Graph &);

private:

    bool bfs(std::vector<std::vector<int>>&, int, std::vector<int>&);

};

#endif
