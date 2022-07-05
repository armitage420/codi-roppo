#include<bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

ll binary_search(vector<ll>& tp, int n, ll bid){
    ll res = -1L, c = -1L;
    int start = 0, end = n-1, mid, idx;

    while(start <= end){
        mid = start + (end-start)/2;

        cout << start << " " << mid << " " << end << " " << tp[mid]  << " " << (tp[mid]*c) << "\n"; // 0 1 2 -2 , 2 2 2 -2
        if((tp[mid] > 0 && tp[mid] <= bid) || (tp[mid] < 0 && tp[mid]*c < bid)){
            start = mid+1; // 2
            cout << "here at start " << (tp[mid]*c) << " " << bid << "\n";
            if(tp[mid] > 0){
                idx = mid; // 1
                res = tp[mid]; // 2
            }
        }else{
            end = mid-1; // 2
        }
    }

    if(res > 0){
        tp[idx] *= -1L;
    }
    
    return res;
}

void solve(vector<ll>& tp, int n, vector<ll>& cb, int m){ 
    sort(tp.begin(), tp.end());

    for(int i=0; i<m; i++){
        ll res = binary_search(tp, n, cb[i]);
        cout << res << "\n";
    }
}

void input(vector<ll>& tp, int& n, vector<ll>& cb, int& m){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        ll x;
        cin >> x;

        tp.push_back(x);
    }

    for(int i=0; i<m; i++){
        ll x;
        cin >> x;

        cb.push_back(x);
    }
}

int main(){
    fastio

    int n, m;
    
    vector<ll> tickets_price;
    vector<ll> customer_bid;
    
    input(tickets_price, n, customer_bid, m);
    
    solve(tickets_price, n, customer_bid, m);
    
    return 0;
}