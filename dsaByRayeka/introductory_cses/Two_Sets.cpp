#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

void display(vector<ll>& v){
    cout << "\n" << v.size() << "\n";
    for(auto i : v){
        cout << i << " ";
    }
}

void solve(ll n){
    ll total_sum = (n * (n+1))/2LL;
    if(n < 3 || (total_sum % 2 == 1)){
        cout << "NO\n";
    }else{
        cout << "YES";
        ll half_sum = total_sum/2LL;
        vector<ll> v1, v2;

        for(int i=n; i>=1; i--){
            if(half_sum - i >= 0){
                v1.push_back(i);
                half_sum -= i;
            }else{
                v2.push_back(i);
            }
        }

        display(v1);
        display(v2);

        cout << "\n";
    }
}

int main(){
    fast;

    ll n;
    cin >> n;
    
    solve(n);
}