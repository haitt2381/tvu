// Graph.cpp

#include "Graph.h"
#include <stack>
#include <queue>

// Constructor
Graph::Graph() : n(0) {
    // Optionally initialize adjacency matrix and global label array
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            a[i][j] = 0;
        }
        globalLabel[i] = 0;
    }
}

void Graph::inputGraph() {
    cout << "Enter the number of vertices: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Enter the element a[" << i+1 << "][" << j+1 << "]: ";
            cin >> a[i][j];
        }
    }
}

void Graph::printGraph() const {
    cout << "The number of vertices is " << n << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(6) << a[i][j];
        }
        cout << endl;
    }
}

void Graph::saveGraphToFile(const string& filename) const {
    fstream f;
    f.open(filename, ios::out);
    f << n << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            f << a[i][j] << " ";
        }
        f << endl;
    }
    f.close();
}

void Graph::readGraphFromFile(const string& filename) {
    fstream f;
    f.open(filename, ios::in);
    f >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            f >> a[i][j];
        }
    }
    f.close();
}

bool Graph::isUndirectedGraph() const {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int Graph::getVertexDegree(int vertex) const {
    int degree = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][vertex] == 1) {
            degree++;
        }
    }
    return degree;
}

int Graph::findVertexWithMaxDegree() const {
    int maxVertex = 0;
    for (int i = 1; i < n; i++) {
        if (getVertexDegree(i) > getVertexDegree(maxVertex)) {
            maxVertex = i;
        }
    }
    return maxVertex;
}

void Graph::printVertexDegree() const {
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i+1 << " degree is " << getVertexDegree(i) << endl;
    }
}

void Graph::markConnectedComponents(int i, int label) {
    globalLabel[i] = label;

    for (int j = 0; j < n; j++) {
        if (globalLabel[j] == 0 && a[i][j] != 0) {
            markConnectedComponents(j, label);
        }
    }
}

int Graph::countConnectedComponents() {
    int connectedCount = 0;
    for (int i = 0; i < n; i++) {
        globalLabel[i] = 0;  // Reset label array
    }

    for (int i = 0; i < n; i++) {
        if (globalLabel[i] == 0) {
            connectedCount++;
            markConnectedComponents(i, connectedCount);
        }
    }

    return connectedCount;
}

void Graph::printConnectedComponent(int connectedCount) const {
    for (int i = 1; i <= connectedCount; i++) {
        cout << "The connected component " << i << " has vertices: ";
        for (int j = 0; j < n; j++) {
            if (globalLabel[j] == i) {
                cout << setw(6) << j + 1;
            }
        }
        cout << endl;
    }
}

void Graph::DFS(int s) {
    int visited[MAX];
    stack<int> myStack;

    //init
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    myStack.push(s);
    while (!myStack.empty()) {              //Khi stack vẫn còn du lieu
        // xet dinh o dau stack
        int v = myStack.top();
        myStack.pop();

        if (visited[v] != 1) {              //neu v chua duoc duyet
            cout << setw(6) << v;         //print
            visited[v] = 1;                 //duyet v
            for (int i = 0; i < n; i++) {   // xet cac dinh chua duyet co noi voi v
                if (visited[i] == 0 && a[v][i] != 0) {
                    myStack.push(i);
                }
            }
        }
    }
}

void Graph::BFS(int s) {
    int visited[MAX];
    queue<int> myQueue;

    for (int i=0; i < n; i++) { // int
        visited[i] = 0;
    }

    myQueue.push(s);
    while (!myQueue.empty()) {
        int v = myQueue.front();
        myQueue.pop();

        if(visited[v] == 0) {
            cout << setw(6) << v;
            visited[v] = 1;
            for (int i = 0; i < n; i++) {
                if (visited[i] == 0 && a[v][i]) {
                    myQueue.push(i);
                }
            }
        }
    }
}

bool Graph::isEulerGraph() const {
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            degree += a[i][j];
        }
        if (degree % 2 == 1) {
            return false;
        }
    }

    return true;
}


