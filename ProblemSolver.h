#ifndef PROBLEMSOLVER_H
#define PROBLEMSOLVER_H

#include <iostream>
#include <string>
#include <vector>
#include "Graph.h"
#include "ProblemSolution.h"

class ProblemSolver {
public:

    ProblemSolver() = default;

    virtual ~ProblemSolver() {}

    virtual ProblemSolution * solve(const Graph &) = 0;

protected:

    // Source
    int src;
    // Destination
    int dest;
    // Number of vertices of input graph
    int V;
    // Input graph matrix
    std::vector<std::vector<int>> G;
    // Path array
    std::vector<int> path;
    // Cost array
    std::vector<int> cost;
    // String that represents the problem solved
    std::string pb;
    // Input validity check
    bool is_not_valid;

    void input(int V, bool is_src);

  };

#endif
