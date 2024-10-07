#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

const int MAX = 100;

struct Graph {
    int n;
    int a[MAX][MAX];
};

void inputGraph(Graph &g) {
    cout << "Enter the number of vertices: ";
    cin >> g.n;

    for (int i = 0; i < g.n; i++) {
        for (int j = 0; j < g.n; j++) {
            cout << "Enter the element a[" << i+1 << "][" << j+1 << "]:";
            cin >> g.a[i][j];
        }
    }
}

void printGraph(Graph g) {
    cout << "The number of vertices is " << g.n << endl;
    for (int i = 0; i < g.n; i++) {
        for (int j = 0; j < g.n; j++) {
            cout << setw(6) << g.a[i][j];
        }
        cout << endl;
    }
}

void saveGraphToFile(const string& fn, Graph g) {
    fstream f;
    f.open(fn, ios::out);
    string s = "Xin chao\n xin chao 2";
    f << s;
    f.close();
}

void readGraphFromFile(const string& fn,Graph &g) {
    fstream f;
    f.open(fn, ios::in);
    f >> g.n;
    for (int i = 0; i < g.n; i++) {
        for (int j = 0; j < g.n; j++) {
            f >> g.a[i][j];
        }
    }
    f.close();
}

bool isUndirectedGraph(Graph g) {
    for(int i = 0; i < g.n; i++) {
        for(int j = i+1; j < g.n; j++) {
            if(g.a[i][j] != g.a[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int getVertexDegree (const Graph &g, const int vertex) {
    int degree = 0;
    for(int i = 0; i < g.n; i++) {
        if(g.a[i][vertex] == 1) {
            degree++;
        }
    }
    return degree;
}

int findVertexWithMaxDegree(const Graph &g) {
    int maxVertex = 0;
    for(int i = 1; i < g.n; i++) {
        if (getVertexDegree(g, i) > getVertexDegree(g, maxVertex)) {
            maxVertex = i;
        }
    }
    return maxVertex;
}

void printVertexDegree(const Graph &g) {
    for (int i = 0; i < g.n; i++) {
        cout << "Vertex degree: " << i+1 << " is " << getVertexDegree(g, i) << endl;;
    }
}

Graph g{};
int globalLabel[MAX];

void markConnectedComponents(const int i, const int label) {
    globalLabel[i] = label;

    for (int j=0; j < g.n; j++) {
        if (globalLabel[j] == 0 && g.a[i][j] != 0) {
            markConnectedComponents(j, label);
        }
    }
}

int countConnectedComponents() {
    int connectedCount = 0;
    for (int i = 0; i < g.n; i++) {
        globalLabel[i] = 0;
    }

    for (int i = 0; i < g.n; i++) {
        if(globalLabel[i] == 0) {
            connectedCount++;
            markConnectedComponents(i, connectedCount);
        }
    }

    return connectedCount;
}

void printConnectedComponent(const int connectedCount) {
    for (int i = 1; i <= connectedCount; i++) {
        cout << "The connected component " << i << " has vertices: ";
        for (int j = 0; j < g.n; j++) {
            if (globalLabel[j] == i) {
                cout << setw(6) << j + 1;
            }
        }
        cout << endl;
    }
}

int main() {
    const string fn = "graph2.txt";
    readGraphFromFile(fn, g);
    printGraph(g);
    const string msg = isUndirectedGraph(g) ? "This is undirected graph" : "This is not undirected graph";
    cout << msg << endl;
    cout << "Vertex with max degree is " << findVertexWithMaxDegree(g) + 1 << endl;
    const int connectedCount = countConnectedComponents();
    if (connectedCount == 1) {
        cout << "This graph is connected" << endl;
    } else {
        cout << "This graph is not connected, the graph has " << connectedCount << " connected component" << endl;
    }

    printConnectedComponent(connectedCount);

    return 0;
}
