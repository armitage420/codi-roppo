#include <bits/stdc++.h>
using namespace std;
 
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define in(x) cin>>(x);
#define tc() int test; cin>>test; for(int t = 1; t <= test; t++)
#define For(x, _, $) for(int x = _; x < $; x++)
#define ForC(x, _, $, Condition) for(int x = _; x < $; Condition)
#define vec(v, dt, n) vector<dt> v; for(int i =0; i < n; i++){ int c; cin>>c; v.push_back(c);}
 
typedef long long int ll;
const ll MOD = 1e9+7;
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
void swap(ll &x, ll &y){ll temp = x; x = y; y = temp;}

int bSearch(vector<int> &v, int key) {

    int sIndex = v.size() / 2;
    int start = 0;
    int end = v.size() - 1;
    int answer = -1;

    do {

        sIndex = start + (end - start) / 2;

        if (v[sIndex] > key ) {
            end = sIndex - 1;
        } else if(v[sIndex] < key) {
            start = sIndex + 1;
        } else {
            answer = sIndex;

            // Uncomment below to find first occurence
            // end = sIndex - 1;

            // Uncomment below to find last occurence
            start = sIndex + 1;
        }

    } while(start <= end);

    return answer;
}

void input() {

    int size;
    cin >> size;
    
    vector<int> v;
    for(int i=0; i<size; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int searchKey;
    cin >> searchKey;

    int answer = bSearch(v, searchKey);
    cout << answer;
}
 
void testcases(){
    tc(){
      input();
    }
}
 
int main(){
    fast;

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    input();
    return 0;
}
