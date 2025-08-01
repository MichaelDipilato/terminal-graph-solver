#include <iostream>
#include <limits>
#include "Graph.h"
#include "MinimumSpanningTree.h"
#include "ProblemSolution.h"
#include "MinimumSpanningTreeSolution.h"

using namespace std;


ProblemSolution * MinimumSpanningTree::solve(const Graph &g) {

  V = g.get_nv();

  G = g.get_edges();

  pb = "Minimum spanning tree";

  int no_edge;
  vector<int> selected(V,0);

  no_edge = 0;

  input(V, true);

  selected[src] = 1;

  int x;
  int y;

  while (no_edge < V - 1) {
    int min = numeric_limits<int>::max();
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (selected[j] == 0 && G[i][j]) {
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
             }
           }
         }
       }
     }

    path.push_back(x);
    path.push_back(y);
    cost.push_back(G[x][y]);
    selected[y] = 1;
    no_edge++;
   }

  return new MinimumSpanningTreeSolution(g.get_name(), pb, path, cost,  V,  g.get_ns());
 }
