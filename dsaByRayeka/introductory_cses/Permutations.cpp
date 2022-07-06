#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);

void swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}

vector<int> beautiful_permutation(int n){
    if(n==1){
        return {1};
    }

    if(n==4){
        return {2,4,1,3};
    }

    if(n < 5){
        return {-1};
    }

    vector<int> res;
    for(int i=1; i<=n; i++){
        res.push_back(i);
    }

    int half = n/2;
    for(int i=1,k=(n%2 == 0) ? (half+1) : (half+2); i<=(n%2 == 0) ? half : (half+1),k<=n; i+=2, k++){        
        swap(res[i-1], res[k-1]);
    }

    return res;
}

int main(){
    fast;

    int n;
    cin >> n;

    auto beautiful_perm = beautiful_permutation(n);

    if(beautiful_perm[0] < 1){
        cout << "NO SOLUTION\n";
    }else{
        for(auto num : beautiful_perm){
            cout << num << " ";
        }
        cout << "\n";
    }
    return 0;
}