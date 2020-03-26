#include <bits/stdc++.h>
#define MOD 1000000007
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define pii pair<ll, ll>
#define endl "\n"
#define FOR(a,b) for (long long i = a; i < b; i++)
#define REV(a,b) for (long long i = b; i > a; i--)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll N;
        cin >> N;
        string s;
        cin >> s;
        unordered_map<char,ll>mp;
        for(ll i=0;i<N;i++) {
            mp[s[i]]++;
        }
        ll cnt = 0;
        ll odd = 0;
        for(auto i=mp.begin();i!=mp.end();i++) {
            cnt += floor((i->S)/2);
            if(i->S%2==1) {
                odd++;
            }
        }
        ll res = cnt;
        for(ll k=cnt;k<=2*cnt;k++) {
            for(ll j=1;j<=odd;j++) {
                if(((k-cnt)*4+2*j)+1<=k+j) {
                    res = max(res, k+j);
                }else {
                    break;
               }
            }
            if(((k-cnt)*4)+1 <=k) {
                res = max(res, k);
            }else {
                break;
            }
        }
        // for(ll k=cnt+1;k<=odd;k++) {
        //     if(((k-cnt)*2)+1<=k) {
        //         res = max(res, k);
        //     }else {
        //         break;
        //     }
        // }
        cout << res << endl;
    }
    return 0;
}
