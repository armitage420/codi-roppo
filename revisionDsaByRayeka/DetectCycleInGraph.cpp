#include<bits/stdc++.h>
using namespace std;

int dfs(vector<int> adj[], int visited1[], int visited2[], int u){
    if(visited2[u]) return 1;
    
    visited1[u] = 1;
    visited2[u] = 1;
    for(auto s: adj[u]){
        if(dfs(adj, visited1, visited2, s)){
            return 1;
        }
    }
    visited2[u] = 0;
    return 0;
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

    int visited1[n] = {0};
    int visited2[n] = {0};
    int flag = 0;
    for(int i=0; i<n; i++){
        if(!visited1[i] && dfs(adj, visited1, visited2, i)){
            flag = 1;
            break;
        }
            
    }

    if(flag)
        cout << "Yes.\n";
    else
        cout << "No.\n";

}