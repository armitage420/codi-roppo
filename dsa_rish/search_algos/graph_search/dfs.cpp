#include <bits/stdc++.h>
#include <iterator>
using namespace std;

void dfsInternal(vector<int> adj[], bool visit[], int node) {

    if(visit[node]) {
        return;
    }

    visit[node] = true;
    cout << "Visiting node : " << node + 1 << "\n";
    for( auto u : adj[node] ) {
        dfsInternal(adj, visit, u);
    }
}

void dfs(vector<int> adj[], int size) {

    bool visit[size] = {false};

    for(int i=0; i<size; i++) {
        dfsInternal(adj, visit, i);
    }
}

void printGraph(vector<int> adj[], int size) {
    
    for(int i=0; i<size; i++) {
        cout<<"Node "<<i+1<<" : ";
        for( auto s : adj[i] )
            cout<<s+1<<" ";
        cout<<"\n";
    }
}

void input() {

    int nodeCount;
    cin >> nodeCount;

    vector<int> adj[nodeCount];

    int edgeCount;
    cin >> edgeCount;

    for(int i=0; i<edgeCount; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1-1].push_back(v2-1);
    }

    // Uncomment this line below to visualize the graph
    // printGraph(adj, nodeCount);

    dfs(adj, nodeCount);
}
 
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    input();

    return 0;
}
