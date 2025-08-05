#include <iostream>
#include <limits>
#include "Graph.h"
#include "ProblemSolution.h"
#include "SingleSourceShortestPath.h"
#include "SingleSourceShortestPathSolution.h"

using namespace std;

ProblemSolution * SingleSourceShortestPath::solve(const Graph &g) {

    V = g.get_nv();

    G = g.get_edges();

    src = 0;

    pb = "Single-source shortest path";

    input(V,true);

    vector<int> dist(V,numeric_limits<int>::max());

    vector<bool> sptSet(V,false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {

        int u = min_distance(dist, sptSet, V);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)

            if (!sptSet[v] && G[u][v]
                && dist[u] != numeric_limits<int>::max()
                && dist[u] + G[u][v] < dist[v])
                dist[v] = dist[u] + G[u][v];
    }

    for (int i = 0; i < V; i++) {
        path.push_back(src);
        path.push_back(i);
        cost.push_back(dist[i]);
    }

    return new SingleSourceShortestPathSolution(g.get_name(), pb, path, cost, V, g.get_ns());
}

int SingleSourceShortestPath::min_distance(vector<int> dist, vector<bool> sptSet, int V) {

    int min = numeric_limits<int>::max(), min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}
