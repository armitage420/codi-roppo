#include <bits/stdc++.h>
using namespace std;

void swap(vector<int>& arr, int i, int j){
    int num = arr[i];
    arr[i] = arr[j];
    arr[j] = num;
}

int getIdx(vector<int>& arr, int start, int end, bool nondescreasing){
    
    int minIdx = start;
    for(int i = start+1; i < end; i++){
        if(nondescreasing && arr[i] < arr[minIdx]){
            minIdx = i;
        }else if(!nondescreasing && arr[i] > arr[minIdx]){
            minIdx = i; //maxIdx for this case
        }
    }
    
    return minIdx;
}

void selectionSort(vector<int>& arr, bool nondescreasing){
    int n = arr.size();
    
    for(int start=0; start < n-1; start++){
        int minIdx = getIdx(arr, start, n, nondescreasing);
        swap(arr, start, minIdx);
    }
}

int main(){
    // true for ascending and false for descending order
    
    vector<int> arr = {2, 1, 3, 5, 7, 12};
    selectionSort(arr, false);
    for(int num : arr){
        cout << num << " ";
    }
    return 0;
}