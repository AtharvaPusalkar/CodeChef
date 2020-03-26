#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 2e9
#define EPS 1e-9
#define MAX LLONG_MAX
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
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll mod(string n, int x) {
    ll res = 0;
    for (ll i = 0; i < n.length(); i++)
         res = (res*10 + (int)n[i] - '0') %x;

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll A, B;
        cin >> A >> B;
        if(A==B) {
            cout << -1 << endl;
        }else {
            ll res=0;
            A -= 1;
            B -= 1;
            ll P = max(A, B);
            FOR(i, 1, P+1) {
                if(mod(to_string(A), i) == mod(to_string(B), i)) {
                    res++;
                }
            }
            cout << res << endl;
        }
    }
    return 0;
}
