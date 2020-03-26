#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 2e9
#define EPS 1e-9
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define endl "\n"
#define FOR(i,a,b) for (long long i = a; i < b; i++)
#define REV(i,a,b) for (long long i = a; i > b; i--)
#define mset(a, v) memset(a, v, sizeof(a))
typedef std::pair<int, int> pii;
typedef std::vector<long long> vi;
typedef std::vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll solve(ll x,ull y,ll p) {
    ll res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll N;
        cin >> N;
        ll B[N];
        FOR(i,0,N) {
            cin >> B[i];
        }
        sort(B,B+N);
        ll last = __builtin_popcountll(B[0]);
        ll res = 1;
        bool flag = true;
        FOR(i,1,N) {
            if(__builtin_popcountll(B[i])<last) {
                flag = false;
                break;
            }else {
                res = ((res)%MOD * solve(2, last, MOD))%MOD;
//                cout << "i #" << i+1 << " " << res << endl;
                last = __builtin_popcountll(B[i]);
            }
        }
        (flag)? cout << res << endl : cout << "0" << endl;
    }
    return 0;
}
