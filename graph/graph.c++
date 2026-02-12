#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    // Create adjacency matrix V x V initialized with 0
    vector<vector<int>> graph(V, vector<int>(V, 0));

    bool undirected;
    cout << "Is the graph undirected? (1 for Yes, 0 for No): ";
    cin >> undirected;

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        graph[u][v] = 1;

        if (undirected) {
            graph[v][u] = 1;
        }
    }

    // Print adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
