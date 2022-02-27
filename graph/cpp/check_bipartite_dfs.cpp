#include<bits/stdc++.h>

using namespace std;

bool dfsCheck(int node, vector<int> graph[], vector<int>& colored){

    for(auto connectedNode: graph[node]){
        if(colored[connectedNode]==-1){
            colored[connectedNode] = 1 - colored[node];
            // return dfsCheck(connectedNode, graph, colored);
            if(!dfsCheck(connectedNode, graph, colored)) return false;
        }else{
            if(colored[connectedNode]==colored[node]){
                return false;
            }
        }
    }

    return true;
}

bool checkBipartite(vector<int> graph[], vector<int>& colored, int n){
       for(int i = 1; i<=n; i++){
           if(colored[i] == -1){
                colored[i] = 1;
                if(!dfsCheck(i, graph, colored)){
                    return false;
                }
           }
       }
       return true;
}

int main(){

    int n, m, u, v;
    cin >> n >> m;
    bool isBipartite;
    vector<int> graph[n+1];
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> colored(n+1, -1);

    isBipartite = checkBipartite(graph, colored, n);

    if(isBipartite){
        cout << "Graph is Bipartite" << endl;
    }else{
        cout << "Graph is not Bipartite" << endl;
    }

    return 0;
}