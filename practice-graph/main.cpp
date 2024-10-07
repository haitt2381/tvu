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

int main() {
    const string fn = "graph.txt";
    Graph g1{};
    readGraphFromFile(fn, g1);
    // inputGraph(g1);
    printGraph(g1);
    const string msg = isUndirectedGraph(g1) ? "This is undirected graph" : "This is not undirected graph";
    cout << msg << endl;
    // saveGraphToFile(g1);
    return 0;
}
