// Check if a bipartite graph with BFS 
#include <bits/stdc++.h>

using namespace std;


bool checkBipartite(vector<int> graph[], vector<int>& colored, int n,int m){
    // n -> no of nodes, m -> no of edges
    queue<int> q;
    int top;
    int color = 1;
    for(int i = 1; i <= n; i++){
        if(colored[n]==-1){
            q.push(i);
            colored[i] = color;
            while(!q.empty()){
                top = q.front();
                q.pop();
                for(auto node: graph[top]){
                    if(colored[node]==-1){
                        q.push(node);
                        colored[node] = 1 - colored[top];
                    }else{
                        if(colored[node] == colored[top]){
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main(){

    int n, m, u, v;
    cin >> n >> m;
    // n -> no of nodes, m -> no of edges
    vector<int> graph[n+1];
    for(int i = 1; i<=m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> colored(n+1, -1);

    bool isPartite = checkBipartite(graph, colored, n, m);

    if(isPartite) cout << "Is Partitite" << endl;
    else cout << "Is Not Partitite" << endl; 
    return 0;
}