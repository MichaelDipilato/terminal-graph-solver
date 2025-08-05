#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <queue>
#include "Graph.h"
#include "MaximumFlow.h"
#include "ProblemSolution.h"
#include "MaximumFlowSolution.h"

using namespace std;

ProblemSolution * MaximumFlow::solve(const Graph &g) {

    int u, v;

    V = g.get_nv();

    G = g.get_edges();


    pb = "Maximum flow between source and destination";

    input(V,true);

    input(V,false);


    vector<vector<int>> rGraph = G;

    vector<int> parent(V);

    int max_flow = 0;

    while (MaximumFlow::bfs(rGraph, V, parent)) {

        int path_flow = numeric_limits<int>::max();
        for (v = dest; v != src; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = dest; v != src; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return new MaximumFlowSolution(g.get_name(), pb, max_flow, V, g.get_ns());
}

bool MaximumFlow::bfs(vector<vector<int>> &rGraph, int V, vector<int> &parent) {

    vector<bool> visited(V, false);

    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                if (v == dest) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return false;
}
