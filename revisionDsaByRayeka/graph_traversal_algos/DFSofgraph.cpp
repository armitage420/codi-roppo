#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], bool visited[], int u){
    if(visited[u]) return;
    cout << u+1 << " ";
    visited[u] = true;
    for(auto s: adj[u]){
        dfs(adj, visited, s);
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> adj[n];
    int v1, v2;
    while(cin >> v1 >> v2){
        adj[v1-1].push_back(v2-1);
    }

    // for(int i=0; i<n; i++){
    //     cout << "for vertex " << i+1 << " ";
    //     for(auto s : adj[i])
    //         cout << s+1 << " ";
    //     cout << "\n";
    // }

    bool visited[n] = {0};
    for(int i=0; i<n; i++)
        if(!visited[i])
            dfs(adj, visited, i);
}