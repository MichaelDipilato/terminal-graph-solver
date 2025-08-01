#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Graph.h"

using namespace std;

bool Graph::get_data(ifstream &f, string filename) {

    // Temporary storage for selected data members of the graph
    string word, w1, s1, s2, s3;
    int n1, n2, w;

    f.open("instances/" + filename);

    // Failed to open file
    if (!f) return false;

    // Extract graph name
    f >> word >> word;
    graph_name = word;

    // Extract number of vertices
    f >> word >> word;
    for (auto c : word) if (isdigit(c)) w1 += c;
    nv = stoi(w1);

    // Extract number of edges
    f >> word >> word;
    w1 = "";
    for (auto c : word) if (isdigit(c)) w1 += c;
    ns = stoi(w1);

    edges = std::vector<std::vector<int>>(nv, std::vector<int>(nv, 0));
    while (f >> s1 >> s2 >> s3) {
        n1 = stoi(s1);
        n2 = stoi(s2);
        w = stoi(s3);
        edges[n1][n2] = w;
        edges[n2][n1] = w;
    }

    // Chiusura file
    f.close();
    return true;
}
