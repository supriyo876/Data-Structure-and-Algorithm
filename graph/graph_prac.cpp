
#include <iostream>
#include <vector>

using namespace std;

/*int main () {

  int v = 3;

  vector<vector<int>> graph (v, vector<int>(v,0));

  // if graph is undirect

  graph[0][1] = 1;
  graph[1][0] = 1;
  graph[1][2] = 1;
  graph[2][1] = 1;

  cout << "adjacency matrix :\n";
  for (int i= 0; i<v; i++){

    for (int j = 0; j<v; j++){
       cout << graph[i][j] << " ";
      }
    cout << endl;
    }
 return 0;
}*/

int main (){

    int v,e;
    cout << "enter number of vartices :";
    cin >> v;
    cout << "enter number of edges :";
    cin >> e;


    vector<vector<int>> graph (v, vector<int>(v,0));

    bool undirect;
    cout << "undirect ? (1 if it is else 0)";
    cin >> undirect;

    cout << "enter edges (u,v) :\n";

    for(int i=0;i<e; i++){
        int u,v;
        cin >> u >> v;
        graph[u][v] = 1;

        if (undirect){
            graph[v][u]= 1;

        }
    }
    //for printing
    cout << "adjaceny matrix is :\n";
    for(int i=0; i<v; i++){
        for (int j=0; j<v; j++){
            cout<<graph[i][j] << " ";

        }
        cout << endl;
    }

    return 0;

}















