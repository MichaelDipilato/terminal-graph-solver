# TERMINAL GRAPH SOLVER

Terminal Graph Solver is a command-line application designed to solve classic graph problems. It provides a simple interface to load graph instances and apply well-known algorithms.

## Features

This app can solve four types of graph problems: 
- Minimum spanning tree using Prim's algorithm;
- Single-source shortest path using Dijkstra's algorithm;
- All-pairs shortest paths using Floyd-Warshall algorithm;
- Maximum flow between source and destination using Ford-Fulkerson algorithm.

## Graph file format

Graph instances are stored in the ```instances/``` directory. Each file must follow a specific format:

```
NAME: graph_name
n: number of vertices/nodes
m: number of edges
first_node<TAB>second_node<TAB>cost.
```
> Be careful when creating new files—incorrect formatting may cause parsing errors.
> You might consider switching to CSV format for easier data handling and compatibility.

## Building with CMake

The project uses CMake to ensure cross-platform compatibility and simplify the build process on both Linux and Windows.

### Linux 

1. Open a terminal in the project root directory
2. Create a build directory:
   ```
   mkdir build && cd build
   ```
3. Generate build files with CMake:
   ```
   cmake ..
   ```
4. Compile the project:
   ```
   cmake --build .
   ```
> Tested on Ubuntu 24.04+. Make sure you have ```g++``` and ```cmake``` installed.

### Windows (Visual Studio)

1. Open CMake GUI or use the terminal.
2. Set the source directory to the project root.
3. Set the build directory (e.g., ```build/```).
4. Click Configure, select your version of Visual Studio.
5. Click Generate, then Open Project.
6. Build the solution in Visual Studio.

### Windows (MinGW)

If you prefer using MinGW from the terminal:
```
mkdir build && cd build
cmake -G "MinGW Makefiles" ..
cmake --build .
```
> Make sure ```mingw32-make``` is installed and available in your system PATH.

## Future improvements

Here are some ideas to enhance the application:

- Add graphical visualization of graphs using a C++ graphics library
- Support alternative input formats like CSV

## About
This project is part of the Sound and Music Computing course at the University of Milan. Feel free to modify, extend, or adapt it to your needs.
This project is licensed under the [MIT License](LICENSE).  
You are free to use, modify, and distribute this software with proper attribution.
