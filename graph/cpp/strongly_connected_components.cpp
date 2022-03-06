// Strongly Connected Components in a Graph --> KosaRaju Algorithm
#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int> graph[], int node, vector<int>& visited, vector<int>& component){

    visited[node]++;
    component.push_back(node);
    for(auto connectedNode: graph[node]){
        if(visited[connectedNode]!=2){
            dfs(graph, connectedNode, visited, component);
        }
    }
}


void dfsTS(vector<int> graph[], int node, vector<int>& visited, stack<int>& s1){
    visited[node] = 1;

    for(auto connectedNode: graph[node]){
        if(visited[connectedNode] == -1){
            dfsTS(graph ,connectedNode, visited, s1);
        }
    }
    cout << node << endl;
    s1.push(node);
}

stack<int> topologicalSort(vector<int> graph[], vector<int>& visited, int n){
    stack<int> s1;
    vector<int> tSorted;
    for(int i = 1; i<=n; i++){
        if(visited[i]==-1) dfsTS(graph, i, visited, s1);
    }
    // cout << "stack size: " << s1.size() << endl;

    // un-comment to get topological Sorted list --> tSort
    // stack<int> s2 = s1;
    // while(!s2.empty()){
    //     tSorted.push_back(s2.top());
    //     s2.pop();
    // }

    return s1;
}

int main(){

    int n, m, u, v;
    cin >> n >> m;

    vector<int> graph[n+1];

    for(int i = 0; i < m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
    }

    cout << "Graph: " << endl;
    for(int i = 1; i <= n; i++){
        cout << i << ": ";
        for(auto node: graph[i]) cout << node << ", ";
        cout << endl;
    }
    cout << endl;

    vector<int> visited(n+1, -1);

    stack<int> tStack = topologicalSort(graph, visited, n);

    vector<int> transposeGraph[n+1];
    for(int i = 0; i < n; i++){
        for(auto node: graph[i]){
            transposeGraph[node].push_back(i);
        }
    }

    cout << "Transpose Graph: " << endl;
    for(int i = 1; i <= n; i++){
        cout << i << ": ";
        for(auto node: transposeGraph[i]) cout << node << ", ";
        cout << endl;
    }

    vector<vector<int>> stronglyConnectedComponents; 

    // for(int i = 1; i <= n; i++) cout << i << ": " << visited[i] << endl;

    while(!tStack.empty()){
        vector<int> component;
        int top = tStack.top();
        if(visited[top]!=2){
            dfs(transposeGraph, top, visited, component);
            stronglyConnectedComponents.push_back(component);
        }
        tStack.pop();
    }

    cout << "Connedted Components: \n{ ";
    for(auto component: stronglyConnectedComponents){
        cout << "{ ";
        for(auto a: component) cout << a << ", " ;
        cout << "}, ";
    }
    cout << " }"<< endl;

    return 0;
}