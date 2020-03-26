#include <bits/stdc++.h>
#define MOD 1000000007
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define FOR(a,b) for (long long i = a; i < b; i++)
#define REV(a,b) for (long long i = b; i > a; i--)
#define pii pair<ll, ll>;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll get_pairs(ll n) {
    ll count = 0;
    ll diff = 1;
    for(ll i=1;i<=n-1;i++) {
        count += diff;
        diff += 1;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll N;
        cin >> N;
        vector<ll>pos_0;
        vector<ll>pos_2;
        ll A;
        for(ll i=0;i<N;i++) {
            cin >> A;
            if(A==0) {
                pos_0.EB(i);
            }else if (A==2) {
                pos_2.EB(i);
            }
        }
        ll res = 0;
        if(pos_0.size()!=1) {
            res += get_pairs(pos_0.size());
        }
        if(pos_2.size()!=1) {
            res += get_pairs(pos_2.size());
        }
        cout << res << "\n";
    }
    return 0;
}