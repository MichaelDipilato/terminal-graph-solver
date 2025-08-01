#ifndef MINIMUMSPANNINGTREE_H
#define MINIMUMSPANNINGTREE_H

#include <vector>
#include "Graph.h"
#include "ProblemSolution.h"
#include "ProblemSolver.h"


class MinimumSpanningTree : public ProblemSolver {
public:

    MinimumSpanningTree() = default;

    ProblemSolution * solve(const Graph &);

};

#endif
