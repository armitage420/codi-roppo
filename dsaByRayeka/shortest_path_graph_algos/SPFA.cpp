#include<bits/stdc++.h>
using namespace std;

void spfa(vector<pair<int, int>> adj[], int n, int node){
    int dist[n];
    dist[0] = 0;
    for(int i = 1; i < n; i++){
        dist[i] = INT_MAX;
    }
    int inQ[n] = {0};

    queue<int> q;
    q.push(node);
    inQ[node] = 1;

    int len[n] = {0};
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto s : adj[u]){
            int v = s.first, wt = s.second;
            if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                len[v] = len[u] + 1;
                if(len[v] == n){
                    cout << "This graph has negative cycle\n";
                    return;
                }
                dist[v] = dist[u] + wt;
                if(!inQ[v]){
                    q.push(v);
                    inQ[v] = 1;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << i+1 << " " << dist[i] << "\n";
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<pair<int, int>> adj[n];
    int u, v, wt;
    while(cin >> u >> v >> wt){
        adj[u-1].push_back(make_pair(v-1, wt));
    }
    spfa(adj, n, 0);
    return 0;
}