#include<bits/stdc++.h>
using namespace std;

bool isBipartite(vector<int> adj[], int n, int u){
    int colorVisited[n] = {0};
    // color 1 --> -1, color 2 --> 1

    colorVisited[u] = -1;
    queue<int> q;
    q.push(u);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto s : adj[x]){
            if(s == x)
                return 0;

            if(!colorVisited[s]){
                colorVisited[s] = -1 * colorVisited[x];
                q.push(s);
            }else if(colorVisited[s] == colorVisited[x]){
                return 0;
            }
        }
    }

    return 1;
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

    isBipartite(adj, n, 0) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}