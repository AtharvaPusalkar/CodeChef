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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll N;
        cin >> N;
        ll A[N], B[N];
        FOR(i,0,N) {
            cin >> A[i];
        }
        FOR(i,0,N) {
            cin >> B[i];
        }
        ll res = 0;
        sort(A,A+N);
        sort(B,B+N);
        FOR(i,0,N) {
            res += min(A[i],B[i]);
        }
        cout << res << endl;
    }
    return 0;
}
