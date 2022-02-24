//Connected Components:
// By Asim Junaid
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    vector<vector<int>> cities={{1, 3}, {3, 4}, {2, 4}, {1, 2}, {2, 3}, {5, 6}};
    int n = 6;
    vector<int> graph[n+1];
    int libraryCost = 0, road_cost = 0;
    for(int i = 0; i < cities.size(); i++){
        int initial, finalD;
        initial = cities[i][0];
        finalD = cities[i][1];
        graph[initial].push_back(finalD);
        graph[finalD].push_back(initial);
    }
    vector<int> visited(n+1, 0);
   
    queue<int> q;
    vector<vector<int>> connectedComponents;
    for(int i = 1; i <= n; i++){
        if(visited[i]==0){
            // If node is not visited, traverse it
            vector<int> adjacent;
            q.push(i);
            while(!q.empty()){
                int top = q.front();
                q.pop();
                if(visited[top]!=1){
                    visited[top] = 1;
                    adjacent.push_back(top);  
                }else{
                    continue;
                }
                for(auto a: graph[top]){
                    if(visited[a]!=1)
                    q.push(a);
                }
            }
            connectedComponents.push_back(adjacent);  
        }
       
    }
        for(auto component:connectedComponents){
            cout << "{ ";
            for(auto vertex:component){
                cout << vertex << " ";
            }
            cout << " }, ";
        }
    return 0;
}