#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);

int count_rep(int&n, string& s){
    if(n==0)
        return 0;

    int max_count = 1, count = 1;
    for(int i=1; i<n; i++){
        if(s[i] != s[i-1]){
            max_count = max(max_count, count);
            count = 0;
        }

        count++;
    }

    if(n > 1 && s[n-1] == s[n-2]){
        max_count = max(max_count, count);
    }

    return max_count;
}

int input(string& s){
    cin >> s;
    return s.length();
}

int main(){
    fast;

    string s;
    int n = input(s);
    
    int longest_rep = count_rep(n, s);
    cout << longest_rep << "\n";
    return 0;
}