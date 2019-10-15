#include <bits/stdc++.h>
#define MOD 1000000007
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define REP(i,a,b) for (long long i = a; i < b; i++)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

bool searchE(ll arr[], ll s, ll x) {
    //ll s = sizeof(arr)/sizeof(arr[0]);
    for(ll i=0;i<s;i++) {
        if(arr[i]==x) {
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin >> t;
    while(t--) {
        ll N, K;
        cin >> N >> K;
        ll arr[N];
        for(ll i=0;i<N;i++) {
            cin >> arr[i];
        }
        ll res[K];
        memset(res, 0, sizeof(res));
        for(ll i=0;i<N;i++) {
            if(searchE(res, K, arr[i])) {
                for(ll j=0;j<K-1;j++) {
                    res[j] = res[j+1];
                }
                res[K-1] = arr[i];
            }
        }
        for(ll i=K-1;i>=0;i--) {
            if(res[i]>0){
                 cout << res[i] << " ";
            }
        }
    }
    return 0;
}
