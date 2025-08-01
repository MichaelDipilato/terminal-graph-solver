#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Graph {
public:
    Graph() = default;

    Graph(std::string name, int n, int s, std::vector<std::vector<int>> e) :
    graph_name(name), nv(n), ns(s), edges(e) {}

    Graph(const Graph &orig):
    graph_name(orig.graph_name), nv(orig.nv), ns(orig.ns), edges(orig.edges) {}

    Graph& operator=(const Graph &rhs) {
        graph_name = rhs.graph_name;
        nv = rhs.nv;
        ns = rhs.ns;
        edges = rhs.edges;
        return *this;
    }

    ~Graph() = default;

    // Read graph data
    bool get_data(std::ifstream &f,std::string filename);

    std::string get_name() const { return graph_name; }
    int get_nv() const { return nv; }
    int get_ns() const { return ns; }
    std::vector<std::vector<int>> get_edges() const { return edges; }

private:

    std::string graph_name;
    // Number of vertices
    int nv;
    // Number of edges
    int ns;
    // Graph matrix
    std::vector<std::vector<int>> edges;
    
};

#endif
