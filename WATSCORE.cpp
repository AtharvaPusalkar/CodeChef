#include <bits/stdc++.h>
#define MOD 1000000007
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define FOR(a,b) for (long long i = a; i < b; i++)
#define REV(a,b) for (long long i = b; i > a; i--)
#define endl "\n"
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
        unordered_map<ll,ll>mp;
        ll PI, SI;
        for(ll i=0;i<N;i++) {
            cin >> PI >> SI;
            mp[PI] = max(mp[PI], SI);
        }
        ll res = 0;
        for(auto it = mp.begin();it!=mp.end();it++) {
            if(it->F<=8) {
                res += it->S;
            }
        }
        cout << res << endl;
    }
    return 0;
}
