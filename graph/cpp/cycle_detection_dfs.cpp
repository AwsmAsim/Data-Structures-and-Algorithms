// CYCLE DETECTION IN UNDIRECTED GRAPH by DFS
#include <bits/stdc++.h>

using namespace std;

bool isCycle(int node, int parent, vector<int> graph[], vector<int>& visited){
    visited[node] = 1;
    for(auto connectedNodes: graph[node]){
        if(!visited[connectedNodes]){
            if(isCycle(connectedNodes, node, graph, visited)) return true;
        }else{
            if(parent != connectedNodes){
                return true;
            }
        }
    }
    return false;
}

int main(){

    int n, m, u, v;   
    cin >> n >> m;
    bool cycle = false;

    vector<int> graph[n+1]; 

    for(int i = 1; i <= m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> visited(n+1, 0);

    // Un-comment to print Adjacency matrix
    // cout << "\nAdjacency Matrix:\n";
    // for(int i = 1; i <= n; i++){
    //     cout << i << ": ";
    //     for(auto a: graph[i]){
    //         cout << a << ", ";
    //     }
    //     cout << endl;
    // }
    // cout << "\n";

    for(int i = 1; i<= n; i++){
        if(visited[i]==0){
            if(isCycle(i, -1, graph, visited)){
                cycle = true;
                break;
            } 
        }
    }

    if(cycle){
        cout << "Cycle present\n";
    }else{
        cout << "No cycle found\n";
    }

    return 0;
}