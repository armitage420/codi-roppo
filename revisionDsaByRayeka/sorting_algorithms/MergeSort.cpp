#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& v, int left, int mid, int right, bool nondecreasing){
    int lsize = mid - left + 1;
    int rsize = right - mid;

    // creating temp arrays
    auto *leftArray = new int[lsize];
    auto *rightArray = new int[rsize];

    for(int i=0; i<lsize; i++){
        leftArray[i] = v[left+i];
    }
    for(int i=0; i<rsize; i++){
        rightArray[i] = v[mid+1+i];
    }

    int i=0, j=0, k=left;
    while (i < lsize && j < rsize)
    {
        if((nondecreasing && leftArray[i] < rightArray[j]) || (!nondecreasing && leftArray[i] > rightArray[j])){
            v[k] = leftArray[i];
            i++;
        }else{
            v[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < lsize)
    {
        v[k] = leftArray[i];
        i++;
        k++;
    }
    
    while (j < rsize)
    {
        v[k] = rightArray[j];
        j++;
        k++;
    }
    
}

void mergeSort(vector<int>& v, int low, int high, bool nondecreasing){
    if(low < high){
        int mid = low + (high - low)/2;
        mergeSort(v, low, mid, nondecreasing);
        mergeSort(v, mid+1, high, nondecreasing);
        merge(v, low, mid, high, nondecreasing);
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

    // true for ascending order and false for descending
    mergeSort(v, 0, n-1, false);

    for(int num : v){
        cout << num << " ";
    }

    return 0;
}