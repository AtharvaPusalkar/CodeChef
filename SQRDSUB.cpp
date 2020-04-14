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
#define REV(i,a,b) for (long long i = a; i >= b; i--)
#define mset(a,v) memset(a, v, sizeof(a))
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
        int N;
        cin >> N;
        int A[N];
        FOR(i,0,N) {
            cin >> A[i];
            A[i] = abs(A[i]);
        }
        int dp[100];
        mset(dp,0);
        ll res = 0;
        FOR(i,0,N) {
            int tmp[100];
            mset(tmp,0);
            A[i] = A[i]%100;
            tmp[A[i]]++;
            if(A[i]%4==0 || A[i]%2 == 1) {
                res++;
            }
            FOR(j,0,100) {
                if(dp[j]!=0){
                    if(j*A[i]%4==0 || j*A[i]%2==1) {
                        res += dp[j];
                    }
                }
                tmp[(j*A[i])%100] += dp[j];
            }
            FOR(j,0,100) {
                dp[j] = tmp[j];
//                if(tmp[j]!=0) {
//                    cout << tmp[j] << " ";
//                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
