This terminal app allowes you to solve some graph problems.
It provides a simple graphical interface that helps you to figure out how to use this app.
It can solve four problems: 
- Minimum spanning tree using Prim's algorithm;
- Single-source shortest path using Dijkstra's algorithm;
- All-pairs shortest paths using Floyd-Warshall algorithm;
- Maximum flow between source and destination using Ford-Fulkerson algorithm.

There are already some graph descriptions in the "instances" directory; they use a specific file format: be careful when creating new files, you might encounter some issues if you don't follow this format.
You must specify:
NAME: graph_name
n: number of vertices/nodes
m: number of edges
first_node TAB second_node TAB cost.
Feel free to check these files to understand better how these files work. It also might be a good idea to change this whole app to handle, for example, CSV files, in order to store graph description in that format.
