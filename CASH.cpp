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
        ll N,K;
        cin >> N >> K;
        ll A[N];
        FOR(i,0,N) {
            cin >> A[i];
        }
        ll add[N], take[N];
        add[N-1] = K - A[N-1]%K;
        REV(i,N-2,-1) {
            add[i] = (K - A[i]%K) + add[i+1];
        }
        take[0] = A[0]%K;
        FOR(i,1,N) {
            take[i] = A[i]%K + take[i-1];
        }
        ll res = MAX;
        FOR(i,0,N) {
            if(i==N-1) {
                res = min(res,take[N-1]);
            }else if(take[i]>=add[i+1]){
                res = min(res,take[i]-add[i+1]);
            }
        }
        cout << res << endl;
    }
    return 0;
}