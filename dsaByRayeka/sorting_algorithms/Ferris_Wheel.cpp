#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int solve(vector<ll>& w, int n, ll m){
    sort(w.begin(), w.end());

    int start = 0, end = n-1, count = 0;
    while(start <= end){

        ll sum = w[start];
        
        if(start < end){
            sum += w[end];
        }

        if(sum <= m){
            start++;
        }

        end--;
        count++;
    }

    return count;
}

int main(){
    fastio

    int n;
    ll max_allowed;
    cin >> n >> max_allowed;

    vector<ll> weights;
    for(int i=0; i<n; i++){
        ll p;
        cin >> p;

        weights.push_back(p);
    }

    int count = solve(weights, n, max_allowed);

    cout << count << "\n";
    return 0;
}