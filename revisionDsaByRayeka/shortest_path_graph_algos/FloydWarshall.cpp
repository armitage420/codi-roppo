#include<bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> adj, int n){

    int dist[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) dist[i][j] = 0;
            else if(adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j] = INT_MAX;
        }
    }

    for(int intermediate=0; intermediate<n; intermediate++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][intermediate] != INT_MAX && dist[intermediate][j] != INT_MAX && dist[i][j] > dist[i][intermediate] + dist[intermediate][j]){
                    dist[i][j] = dist[i][intermediate] + dist[intermediate][j];
                }
            }
        }
    }

    cout << "Min distances:\n";
    cout << "\t";
    for(int i=0; i<n; i++){
        cout << i+1 << "\t";
    }

    for(int i=0; i<n; i++){
        cout << "\n" << i+1 << "\t";
        for(int j=0; j<n; j++){
            cout << dist[i][j] << "\t";
        }
    }
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<vector<int>> adj;
    vector<int> x;
    for(int j=0; j<n; j++){
        x.push_back(INT_MAX);
    }

    for(int i=0; i<n; i++){
        adj.push_back(x);
    }


    // assuming undirected graph
    int u, v, wt;
    while(cin >> u >> v >> wt){
        adj[u-1][v-1] = wt;
        adj[v-1][u-1] = wt;
    }

    floydWarshall(adj, n);
    return 0;
}

// 5
// 1 2 5
// 1 4 9
// 1 5 1
// 2 3 2
// 3 4 7
// 4 5 2

// Min distances:
// 	1	2	3	4	5	
// 1	0	5	7	3	1	
// 2	5	0	2	8	6	
// 3	7	2	0	7	8	
// 4	3	8	7	0	2	
// 5	1	6	8	2	0	