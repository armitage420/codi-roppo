#include<bits/stdc++.h>
using namespace std;

void swap(vector<int>& v, int i, int j){
    int num = v[i];
    v[i] = v[j];
    v[j] = num;
}

int partition(vector<int>& v, int low, int high, bool nondecreasing){
    int pivot = v[high];
    int pivot_partition = low-1;

    for(int i=low; i<high; i++){
        if((nondecreasing && v[i] < pivot) || (!nondecreasing && v[i] > pivot)){
            pivot_partition++;
            swap(v, i, pivot_partition);
        }
    }

    swap(v, pivot_partition+1, high);
    return pivot_partition+1;
}

void quickSort(vector<int>& v, int low, int high, bool nondecreasing){
    
    if(low < high){
        int partition_idx = partition(v, low, high, nondecreasing);
        quickSort(v, low, partition_idx-1, nondecreasing);
        quickSort(v, partition_idx+1, high, nondecreasing);
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
    
    // true for ascending and false for descending
    quickSort(v, 0, n-1, false);
   
    for(int num : v){
        cout << num << " ";
    }
    return 0;
}