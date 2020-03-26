#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 2e9
#define EPS 1e-9
#define MAX LLONG_MAX
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        ll S[N], V[N], P[N];
        FOR(i,0,N) {
            cin >> S[i] >> P[i] >> V[i];
        }

        ll res = 0;
        //cout << "for " << t << endl;

        FOR(i,0,N) {
            //cout << S[i]/P[i] << endl;
            if((P[i])%(S[i]+1)==0) {
                //cout << "yay" << endl;
                res = max(res, (P[i]/(S[i]+1))*V[i]);
            }else {
                res = max(res,((ll)floor(P[i]/(S[i]+1))*V[i]));
            }
        }
        cout << res << endl;
    }
    return 0;
}
