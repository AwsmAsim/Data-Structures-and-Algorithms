#include <bits/stdc++.h>

using namespace std;

bool dfs(int node, vector<int> graph[], vector<int>& visited){
    visited[node] = 1;
    for(auto connectedNode: graph[node]){
        if(visited[node] == -1){
            if(!dfs(node, graph, visited)) return true;
        }else{
            
            return true;
        }
    }
    return false;
}

int main(){

    int n, m, u, v;
    cin >> n >> m;

    vector<int> graph[n+1];
    for(int i = 1; i <= m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<int> visited(n, -1);

    bool isCycle = dfs(0, graph, visited);

    if(isCycle) cout << "Cycle Found\n";
    else cout << "Cycle NOT Found\n";

    

    return 0;
}