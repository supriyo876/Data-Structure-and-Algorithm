#include <iostream>
using namespace std;
#include <vector>
int main (){

    int e,va;
    cin >> va >> e;
    cout << "vartices :"<< va << " edges :" << e;

    vector<int> arr[va];
    int u,v;
    for (int i=0; i<e; i++){
        cin >> u >> v;
        arr[u].push_back(v); //from u......to v
        arr[v].push_back(u);
    }

    //for printing
    for(int i=0; i<va; i++){

        cout << i << "-->";
        for(int j=0; j<arr[i].size(); j++){
            cout <<arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}
