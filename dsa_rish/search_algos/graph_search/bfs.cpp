#include <bits/stdc++.h>
using namespace std;

void print(vector<int> adj[], int size) {

    for(int i=0; i<size; i++) {
        cout<<"Node "<<i+1<<" : ";
        for ( auto u : adj[i]) {
            cout<<u+1<<" ";
        }
        cout << "\n";
    }
}

void bfsInternal(vector<int> adj[], bool visit[], int node) {

    queue<int> q;

    visit[node] = true;
    q.push(node);

    while(!q.empty()) {

        int nodeToVisit = q.front();
        q.pop();

        cout << "Visiting node : " << nodeToVisit + 1 << "\n"; 

    
        for (auto u : adj[nodeToVisit]) {

            if(visit[u]) {
                continue;
            }

            visit[u] = true;
            q.push(u);
        }
    }
}

void bfs(vector<int> adj[], int size) {

    bool visit[size] = {false};

    for(int i=0; i<size; i++) {
        if (!visit[i]) {
            bfsInternal(adj, visit, i);
        }
    }
}

void input() {

    int nodeCount;
    cin >> nodeCount;

    vector<int> adj[nodeCount];

    int edgeCount;
    cin >> edgeCount;

    for(int i=0; i<edgeCount; i++) {
        int u, v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
    }

    print(adj, nodeCount);

    bfs(adj, nodeCount);
}
   

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    input();

    return 0;
}
