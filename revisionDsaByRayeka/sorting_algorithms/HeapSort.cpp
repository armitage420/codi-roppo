#include <bits/stdc++.h>
using namespace std;

void swap(vector<int>& v, int i, int j){
    int num = v[i];
    v[i] = v[j];
    v[j] = num;
}

void max_heapify(vector<int>& v, int n, int p){
    int largest = p;
    int l = 2*p + 1;
    int r = 2*p + 2;

    if(l<n && v[l] > v[largest]){
        largest = l;
    }

    if(r<n && v[r] > v[largest]){
        largest = r;
    }

    if(largest != p){
        swap(v, largest, p);
        max_heapify(v, n, largest);
    }
}

void merge_sort(vector<int>& v, int n){
    for(int i=n/2-1; i>=0; i--){
        max_heapify(v, n, i);
    }

    for(int i = n-1; i > 0; i--){
        swap(v, 0, i);
        max_heapify(v, i, 0);
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

    merge_sort(v, n);

    for(int num : v){
        cout << num << " ";
    }
    return 0;
}