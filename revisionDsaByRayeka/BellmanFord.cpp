#include<bits/stdc++.h>
using namespace std;

void bellmanFord(vector<pair<int, int>> adj[], int n, int src){

    int dist[n];
    dist[0] = 0;
    for(int i=1; i<n; i++)
        dist[i] = INT_MAX;
    
    // edge list representation will only work if the edges are added in ordered manner
    // bool swapped;
    // for(int i=0; i<n-1; i++){
    //     swapped = 0;
    //     for(auto e : edge){
    //         int u, v, wt;
    //         tie(u, v, wt) = e;

    //         if(dist[u] + wt < dist[v])
    //             dist[v] = dist[u] + wt;
    //     }
    // }

    bool swapped;
    for(int i=0; i<n-1; i++){
        swapped = 0;
        for(int u=0; u<n; u++){
            for(auto x : adj[u]){
                int v = x.first, wt = x.second;
                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                    swapped = 1;
                }      
            }
        }
        // If the minimum values are reached already
        if(!swapped){
            break;
        }
            
    }

    //checking for negative cycle
    for(int u=0; u<n; u++){
        swapped = 0;
        for(auto x : adj[u]){
            int v = x.first, wt = x.second;
            if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
                swapped = 1;
                break;
            }      
        }
        if(swapped){
            break;
        }
            
    }


    if(swapped){
        cout << "The graph contains a negative cycle.";
    }else{
        cout << "Minimum distances from source to each nodes are:- \n";
        cout << "Node distance\n";

        for(int i=0; i<n; i++){
            cout << i+1 << "  " << dist[i] << "\n";
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
    // vector<tuple<int, int, int>> edge;
    vector<pair<int, int>> adj[n];
    int u, v, wt;
    while(cin >> u >> v >> wt){
        // edge.push_back(make_tuple(u-1, v-1, wt));
        adj[u-1].push_back(make_pair(v-1, wt));
    }

    bellmanFord(adj, n, 0);
    return 0;
}

// Test case 1 --> 
// 5
// 1 2 5
// 1 3 3
// 1 4 7
// 3 4 1
// 2 4 3
// 2 5 2
// 4 5 2
// Output-->
// Minimum distances from source to each nodes are:- 
// Node distance
// 1  0
// 2  5
// 3  3
// 4  4
// 5  6

// Test case --> 2
// 2
// 1 2 -2
// 2 1 -2

// The graph contains a negative cycle.