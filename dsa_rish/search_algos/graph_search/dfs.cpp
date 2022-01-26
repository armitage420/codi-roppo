#include <bits/stdc++.h>
#include <iterator>
using namespace std;

void dfsInternal(vector<int> adj[], bool visit[], int start) {

    if(visit[start]) {
        return;
    }

    visit[start] = true;
    cout << " visiting node : " << start + 1 << "\n";
    for( auto u : adj[start] ) {
        dfsInternal(adj, visit, u);
    }
}

void dfs(vector<int> adj[], int size, int start) {

    bool visit[size];

    dfsInternal(adj, visit, start);
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

    // test graph storage
    for(int i=0; i<nodeCount; i++) {
        cout<<"Node "<<i+1<<" : ";
        for( auto s : adj[i] )
            cout<<s+1<<" ";
        cout<<"\n";
    }

    dfs(adj, nodeCount, 4);
}
 
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    input();

    return 0;
}
