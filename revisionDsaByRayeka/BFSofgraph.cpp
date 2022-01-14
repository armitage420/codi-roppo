#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], int n){
    queue<int> q;
    bool visited[n] = {0};
    int distance[n] = {0};
    visited[0] = 1;
    q.push(0);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout << x+1 << " at distance " << distance[x] << "\n"; 
        for(auto s: adj[x]){
            if(visited[s]) return;
            visited[s] = 1;
            distance[s] = distance[x] + 1;

            q.push(s);
        }
    }
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> adj[n];
    int v1, v2;
    while(cin >> v1 >> v2){
        adj[v1-1].push_back(v2-1);
    }

    bfs(adj, n);
}