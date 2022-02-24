#include <bits/stdc++.h>
// Breadth First Search using Queue.

using namespace std;

int main(){

    int n, m, u, v;
    cin >> n >> m; // n -> vertices, m -> edges

    vector<int> graph[n+1];
    for(int i = 0; i < m ;i++){
        cin >> u >> v; // u -> source vertex, v -> destination vertex
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> visited(n+1,-1);
    queue<int> q;
    vector<int> answer;

    for(int i = 1; i < n; i++){
        if(visited[i] == -1){
            q.push(i);
            visited[i] = 1;
            // answer.push_back(i);
            while(!q.empty()){
                int top = q.front();
                q.pop();
                answer.push_back(top);
                for(auto a: graph[top]){
                    if(visited[a] == -1){
                        visited[a] = 1;
                        q.push(a);
                    }
                }
            }

        }

    }
    cout << "answer: " << endl;

    for(auto a: answer){
        cout << a << " ";
    }
    cout << endl;

    return 0;
}