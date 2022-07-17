#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);

void display_output(vector<int>& res){
    int i = 100;

    for(; i>=0; i--){
        if(res[i] > 0)
            break;
    }
    for(; i>=0; i--){
        cout << res[i];
    }
    cout << "\n";
}

vector<int> multiply(vector<int>& num1, vector<int>& num2){
    vector<int> res(100, 0);
    int carry = 0, k;

    for(int i = 0; i < 10; i++){
        k=i;
        for(int j = 0; j < 10; j++){
            int mul = (num1[i]*num2[j]) + carry + res[k];

            res[k] = mul % 10;
            carry = mul/10; 
            k++;
        }
    }

    return res;
}

void populate(vector<int>& num1, vector<int>& num2, string& x, string& y){
    int len1 = x.length(), len2 = y.length(), i=0;
    while(i < max(len1, len2)){

        if(i < len1){
            num1[len1-i-1] = x[i] - '0';
        }

        if(i < len2){
            num2[len2-i-1] = y[i] - '0';
        }
        i++;
    }
}

int main(){
    fast;

    #ifndef ONLINE_JUDGE
        freopen("../../input.txt", "r", stdin);
        freopen("../../output.txt", "w", stdout);
    #endif

    string x, y;
    cin >> x >> y;

    vector<int> num1(30, 0), num2(30, 0);

    populate(num1, num2, x, y);

    vector<int> res = multiply(num1, num2);  

    display_output(res);

    return 0;
}