#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define eb emplace_back
using namespace std;

// C++ program to find given two array
// are equal or not using hashing technique
#include <bits/stdc++.h>
using namespace std;

bool areEqual(vector<ll>arr1,ll arr2[], ll n, ll m) {
    if (n != m)
        return false;
    unordered_map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
        mp[arr1[i]]++;
    for (ll i = 0; i < n; i++) {
        if (mp.find(arr2[i]) == mp.end())
            return false;
        if (mp[arr2[i]] == 0)
            return false;
        mp[arr2[i]]--;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n, e;
        cin >> n;
        vector<ll>C;
        vector<ll>Z;
        ll L[n];
        memset(L,0ll,sizeof(L));
        for(ll i=0;i<n;i++){
            cin >> e;
            C.eb(e);
        }
        for(ll i=0;i<n;i++){
            cin >> e;
             Z.eb(e);
        }
        for(ll i=0;i<n;i++){
            ll lo = max(0ll, i-C[i]);
            ll hi = min(n-1, i+C[i]);
            for(ll j=lo;j<=hi;j++){
                L[j]++;
            }
        }
        if(areEqual(Z, L, n, n)){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
    return 0;
}
