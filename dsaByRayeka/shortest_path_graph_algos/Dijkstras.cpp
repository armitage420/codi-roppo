#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<pair<int, int>> adj[], int n, int node){

    int dist[n];
    dist[node] = 0;

    for(int i=1; i<n; i++){
        dist[i] = INT_MAX;
    }

    int visited[n] = {0};
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, node));

    while(!pq.empty()){

        int u = pq.top().second;
        pq.pop();

        if(visited[u]){
            continue;
        }

        visited[u] = 1;

        for(auto x : adj[u]){
           
            int v = x.first, wt = x.second;
            if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
                // -ve because pq in cpp has default as max heap, and we want the min value on top. 
                pq.push({-1 * dist[v], v});
            }
        }
    }

    for(int i=0; i<n; i++){
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

    dijkstra(adj, n, 0);
    return 0;
}