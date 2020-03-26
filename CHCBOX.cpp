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
        ll N;
        cin >> N;
        ll W[N];
        FOR(i,0,N) {
            cin >> W[i];
        }
        ll first, last;
        ll m = MIN;
        FOR(i,0,N) {
            m = max(m, W[i]);
        }
        FOR(i,0,N) {
            if(W[i]==m) {
                first = i;
                break;
            }
        }
        REV(i,N-1,-1) {
            if(W[i]==m) {
                last = i;
                break;
            }
        }
        if(last-first>((N/2)-1)) {
            cout << 0 << endl;
        }else {
            cout << N - last - (N/2-first) << endl;
        }
    }
    return 0;
}
