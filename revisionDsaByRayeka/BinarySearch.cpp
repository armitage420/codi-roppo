#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &v, int key){
    int ans = -1;

    int start = 0, end = v.size() - 1;
    while(start < end){
        int mid = start + (end - start)/2;
        // cout << mid << " " << v[mid] << "\n";
        if(v[mid] == key){

            ans = mid;
            end = mid -1;
        }else if(v[mid] < key){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }

    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    
    int size;
    cin >> size;
    vector<int> v;
    for(int i =0; i<size; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int key;
    cin >> key;

    int ans = binarySearch(v, key);

    if(ans == -1){
        cout << "Key " << key << " not found.\n";
    }else{
        cout << "Key " << key << " at index " << ans << "\n";
    }
}
