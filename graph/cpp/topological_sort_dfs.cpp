#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int> graph[], vector<int>& visited, stack<int>& st){
    visited[node] = 1;
    cout << node << endl;
    for(auto connectedNode: graph[node]){
        if(visited[connectedNode]==-1){
            dfs(connectedNode, graph, visited, st);
        }
    }
    st.push(node);
}

int main(){

    int n, m, u, v;
    cin >> n >> m;

    vector<int> graph[n];
    for(int i = 0; i<m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
    }

    stack<int> st;
    vector<int> visited(n+1, -1);
    for(int i = 0; i<n; i++){
        if(visited[i] == -1){
            dfs(i, graph, visited, st);
        }
    }

    cout << "Topological Sort: ";
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";


    return 0;
}