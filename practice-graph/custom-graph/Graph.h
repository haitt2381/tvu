// Graph.h

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 100;

class Graph {
private:
    int n;            // Number of vertices
    int a[MAX][MAX];  // Adjacency matrix

public:
    // Constructor
    Graph();

    // Graph input/output
    void inputGraph();
    void printGraph() const;
    void saveGraphToFile(const string& filename) const;
    void readGraphFromFile(const string& filename);

    // Graph properties and operations
    [[nodiscard]] bool isUndirectedGraph() const;
    [[nodiscard]] int getVertexDegree(int vertex) const;
    [[nodiscard]] int findVertexWithMaxDegree() const;
    void printVertexDegree() const;

    // Connected components
    int countConnectedComponents();
    void printConnectedComponent(int connectedCount) const;

    //Algorithm
    void DFS(int s);
    void BFS(int s);

    [[nodiscard]] bool isEulerGraph() const;

private:
    void markConnectedComponents(int i, int label);
    int globalLabel[MAX];  // Global label array for connected components
};

#endif  // GRAPH_H
