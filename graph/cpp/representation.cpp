#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m, u, v;
    cin >> n >> m; // n is no of vertices and m is no of edges

    vector<int> graph[n+1];// vector<pair<int, int>> weightedGraph[n];
    for(int i = 0; i < m; i++){
        cin >> u >> v;  // u is initial vertex and v is source vertexx
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << "Graph: " << endl;
    for(int i = 0; i < n ; i++){
        cout << i << " ";
        for(auto a:graph[i]){
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}