#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

ll solve(vector<ll>& desired_size, vector<ll>& apartment_size, int diff){
    ll count = 0;

    int i=0, j=0, nd = desired_size.size(), na = apartment_size.size(), low, high;
    while(i < nd && j < na){

        low = desired_size[i] - diff; 
        high = desired_size[i] + diff;

        if(apartment_size[j] >= low && apartment_size[j] <= high){
            count++;
            j++;
            i++;
        }else if(apartment_size[j] < desired_size[i]){
            j++;
        }else{
            i++;
        }
    }

    return count;
}

int main(){
    fastio;
    int applicants, apartments;
    ll allowed_diff;

    cin >> applicants >> apartments >> allowed_diff;

    vector<ll> desired_apartment_size;
    for(int i=0; i<applicants; i++){
        ll x;
        cin >> x;

        desired_apartment_size.push_back(x);
    }

    sort(desired_apartment_size.begin(), desired_apartment_size.end());

    vector<ll> apartment_size;
    for(int i=0; i<apartments; i++){
        ll x;
        cin >> x;

        apartment_size.push_back(x);
    }

    sort(apartment_size.begin(), apartment_size.end());

    ll res = solve(desired_apartment_size, apartment_size, allowed_diff);

    cout << res << "\n";

    return 0;
}