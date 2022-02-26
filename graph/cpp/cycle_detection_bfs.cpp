// CYCLE DETECTION IN UNDIRECTED GRAPH by BFS
#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m, u, v;
    //n -> no of nodes/vetices, m->no of edges, u,v -> source and final node of an edge
    cin >> n >> m ;
    vector<int> graph[n+1];
    int flag = 0;

    for(int i = 1; i <= m; i++){
        cin >> u >> v ;
        graph[u].push_back(v);
        graph[v].push_back(u);
        // Since undirected Graph
    }

    vector<int> visited(n+1, 0);
    queue<pair<int, int>> q; // (parent node, traversed node)
    int top;

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


    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){
            q.push({-1, i});
            visited[i] = 1;
            while(!q.empty()){
                top = q.front().second;
                cout << top << endl;
                q.pop();
                for(auto node: graph[top]){
                    if(visited[node] == 0){
                        q.push({top, node});
                        visited[node] = 1;
                    }else{
                        if(node != top ){
                            // cout << "Cycle Found\n";
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }
    }

    if(flag){
        cout << "Cycle Found\n";
    }else cout << "No cycle in the Graph" << endl;

}