#include<bits/stdc++.h>
using namespace std;

void swap(vector<int>& v, int i, int j){
    int num = v[i];
    v[i] = v[j];
    v[j] = num;
}

void insertionSort(vector<int>& v, int n, bool nondecreasing){
    for(int key = 1; key<n; key++){
        int num = v[key];
        int numIdx = key;
        int compIdx = key;

        while(compIdx >= 0 && ((nondecreasing && num <= v[compIdx]) || (!nondecreasing && num >= v[compIdx]))){
            swap(v, compIdx, numIdx);
            numIdx = compIdx;
            compIdx--;
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    // true for ascending order, false for descending order
    insertionSort(v, n, true);

    for(int num : v){
        cout << num << " ";
    }
    return 0;
}