#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; // number of vertices
    vector<vector<int>> adj; // adjacency list

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // function to add edge
    void addEdge(int u, int v) {
        adj[u].push_back(v); // add v to u’s list
        adj[v].push_back(u); // for undirected graph (comment this line for directed)
    }

    // function to display adjacency list
    void display() {
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int v : adj[i])
                cout << v << " ";
            cout << endl;
        }
    }
};

int main() {
    int V = 5; // number of vertices
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Adjacency List of Graph:" << endl;
    g.display();

    return 0;
}
