// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int> graph[], vector<int>& visited,vector<int>& storeDFS){
    storeDFS.push_back(node);
    visited[node] = 1;
    // cout << node << " ";
    for(auto vertex: graph[node]){
        if(visited[vertex]==0)
        dfs(vertex, graph, visited, storeDFS);
    }
    
}

int main() {
    // Write C++ code here
    // cout << "Hello world!";
    int n, m, u, v;
    cin >> n >> m; // n -> vertices, m -> edges
    vector<int> storeDFS;

    vector<int> graph[n+1];
    for(int i = 0; i < m ;i++){
        cin >> u >> v; // u -> source vertex, v -> destination vertex
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<int> visited(n+1, 0);
    
    for(int i = 1; i < n; i++){
        if(visited[i]==0){
            dfs(i, graph, visited, storeDFS);
        }
    }
    
    cout << "\n" << "DFS: ";
    for(auto a: storeDFS){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}