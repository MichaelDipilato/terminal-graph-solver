#include <iostream>
#include <limits>
#include "Graph.h"
#include "AllPairsShortestPath.h"
#include "ProblemSolution.h"
#include "AllPairsShortestPathSolution.h"

using namespace std;

ProblemSolution * AllPairsShortestPath::solve(const Graph &g) {

    int i, j, k;
    int INF = numeric_limits<int>::max();

    V = g.get_nv();

    G = g.get_edges();

    // Descrizione problema
    pb = "All-pairs shortest paths";

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (G[i][j] == 0 && i != j) G[i][j] = INF;
        }
    }

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (G[i][j] > (G[i][k] + G[k][j])
                    && (G[k][j] != INF
                    && G[i][k] != INF))
                    G[i][j] = G[i][k] + G[k][j];
            }
        }
    }

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {

            path.push_back(i);
            path.push_back(j);
            cost.push_back(G[i][j]);
        }

    }

    return new AllPairsShortestPathSolution(g.get_name(), pb, path, cost, V, g.get_ns());

}
