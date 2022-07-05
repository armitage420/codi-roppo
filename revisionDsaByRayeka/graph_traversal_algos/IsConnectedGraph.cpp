#include<bits/stdc++.h>
using namespace std;

void dfsUtil(vector<int> adj[], int visited[], int u){
    if(visited[u]) return;
    visited[u] = 1;
    for(auto s : adj[u]){
        if(!visited[s])
            dfsUtil(adj, visited, s);
    }
}

int isConnected(vector<int> adj[], int n){
    int visited[n] = {0};
    dfsUtil(adj, visited, 0);

    for(auto s : visited)
        if(!s)
            return 0;
    return 1;
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

    if(isConnected(adj, n))
        cout << "Yes.\n";
    else 
        cout << "No.\n";
}