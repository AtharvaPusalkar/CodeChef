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
        vector<ll>A;
        vector<ll>B;
        ll res = 0;
        ll n,e,curr;
        cin >> n;
        for(ll i=0;i<n;i++){
            cin >> e;
            A.pb(e);
        }
        for(ll i=0;i<n;i++){
            cin >> e;
            B.pb(e);
        }
        for(ll i=0;i<n;i++){
            curr = A[i]*20 - B[i]*10;
            curr = max(0ll,curr);
            res = max(res, curr);
        }
        cout << res << "\n";
    }
    return 0;
}
