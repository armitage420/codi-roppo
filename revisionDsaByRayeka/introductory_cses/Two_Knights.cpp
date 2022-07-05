#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

ll non_attack_ways(ll k){
    ll total_ways = (ll)(k*k*((k*k)-1))/2;

    ll attack_ways = (ll)(4 * (k-1) * (k-2));
    
    return (total_ways - attack_ways);
}

void solve(ll n){
    for(ll i=1; i<=n; i++){
        ll res = non_attack_ways(i);
        cout << res << "\n"; 
    }
}

int main(){
    int n;
    cin >> n;

    solve(n);
    return 0;
}