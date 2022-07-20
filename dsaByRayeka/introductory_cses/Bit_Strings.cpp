#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define MOD 1000000007;
typedef long long int lli;

lli power(lli b, lli n){
    if(n <= 0){
        return 1;
    }

    if(n==1){
        return b;
    }

    if((n&1) == 1){
        return (b * power(b, n/2) * power(b, n/2)) % MOD;
    }

    return (power(b, n/2) * power(b, n/2)) % MOD;
}

lli solve(lli n){
    lli res = power(2LL, n) % MOD;
    return res;
}

int main(){
    fast;

    lli n;
    cin >> n;

    lli res = solve(n);
    cout << res << "\n";
    return 0;
}