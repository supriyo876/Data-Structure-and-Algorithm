#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Number of vertices
    int V = 3;

    // Create V x V adjacency matrix initialized with 0
    vector<vector<int>> graph(V, vector<int>(V, 0));

    // Add edges  if graph is directed
    //graph[0][1] = 1;   // Edge from 0 -> 1
    //graph[1][2] = 1;   // Edge from 1 -> 2

    // if graph is undirected
    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[2][1] = 1;


    // Print adjacency matrix
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
