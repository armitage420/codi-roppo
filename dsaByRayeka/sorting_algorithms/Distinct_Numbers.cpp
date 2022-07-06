#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& v, int n){
    long long distinctCount = 0;

    sort(v.begin(), v.end());

    for(int i=0; i<n-1; i++){
        
        if(v[i] != v[i+1]){
            distinctCount++;
        }
    }

    return ++distinctCount;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> v;
    for(int i=0; i<n; i++){
        long long x;
        cin >> x;

        v.push_back(x); 
    }

    long long res = solve(v, n);
    cout << res << "\n";

    return 0;
}