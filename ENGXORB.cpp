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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int N, P, Q;
        cin >> N >> Q;
        int A[N];
        FOR(i,0,N) {
            cin >> A[i];
        }
        int odd = 0, even = 0;
        FOR(i,0,N) {
            if(__builtin_popcount(A[i])%2==1) {
                odd++;
            }else {
                even++;
            }
        }
//        cout << "dataset -> " << even << " " << odd << endl;
        while(Q--) {
            cin >> P;
            if(__builtin_popcount(P)%2==1) {
                cout << odd << " " << even << endl;
            }else {
                cout << even << " " << odd << endl;
            }
//          cout << "P = " << P << " POP = " << __builtin_popcount(P) << " -> " << odd << " " << even << endl;
        }
    }
    return 0;
}
