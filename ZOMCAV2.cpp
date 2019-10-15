#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define eb emplace_back
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n, e;
        cin >> n;
        vector<ll>C;
        vector<ll>Z;
        ll L[n];
        for(ll i=0;i<n;i++){
            cin >> e;
            C.eb(e);
        }
        for(ll i=0;i<n;i++){
            cin >> e;
             Z.eb(e);
        }
        ll pre_1=0;
        ll m;
        for(ll i=0;i<n;i++){
            ll lo = max(0ll, i-C[i]);
            ll hi = min(n-1, i+C[i]);
            pre_1 += hi-lo+1;
            m = max(m, C[i]);
        }
        ll pre_2=0;
        for(ll i=0;i<n;i++){
            pre_2 += Z[i];
            if(Z[i]>m){
                break;
            }
        }
        if(pre_2==pre_1){
            cout << "YES" << "\n";
        }else if(pre_2 < pre_1 || pre_2 > pre_1){
            cout << "NO" << "\n";
        }
    }
    return 0;
}
