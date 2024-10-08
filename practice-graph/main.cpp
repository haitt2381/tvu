#include "custom-graph/Graph.h"

int main() {
    Graph graph;

    const string fn = "graph2.txt";
    graph.readGraphFromFile(fn);
    graph.printGraph();

    const string msg = graph.isUndirectedGraph() ? "This is an undirected graph" : "This is not an undirected graph";
    cout << msg << endl;

    cout << "Vertex with max degree is " << graph.findVertexWithMaxDegree() + 1 << endl;

    int connectedCount = graph.countConnectedComponents();
    if (connectedCount == 1) {
        cout << "This graph is connected" << endl;
    } else {
        cout << "This graph is not connected, it has " << connectedCount << " connected components" << endl;
    }

    graph.printConnectedComponent(connectedCount);

    return 0;
}

