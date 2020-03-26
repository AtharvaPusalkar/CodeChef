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
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int N, Q;
        cin >> N >> Q;
        int A[N];
        FOR(i,0,N) {
            cin >> A[i];
        }
        pii up[N];
        up[N-1] = {N-1,A[N-1]};
        REV(i,N-2,-1) {
            if(A[i]<A[i+1]) {
                up[i] = up[i+1];
            }else {
                up[i] = {i,A[i]};
            }
        }
        pii dwn[N];
        dwn[N-1] = {N-1,A[N-1]};
        REV(i,N-2,-1) {
            if(A[i]>A[i+1]) {
                dwn[i] = dwn[i+1];
            }else {
                dwn[i] = {i,A[i]};
            }
        }
        while(Q--) {
            int x1, x2, y;
            cin >> x1 >> x2 >> y;
            int res = 0;
            int i = x1;
            while(i<x2) {
//                if(ints(i, A[i-1], i+1, A[i], x1, y, x2, y)) {
//                    res++;
//                }
                if(A[i-1]==y || A[i]==y) {
                    res++;
                }else if (A[i-1]<=y&&A[i]>=y) {
                    res++;
                }else if (A[i-1]>=y&&A[i]<=y) {
                    res++;
                }
                if(up[i].S > y) {
                    i = up[i].F;
                }else if(dwn[i].S < y) {
                    i = dwn[i].F;
                }else {
                    i++;
                }
                cout << "aahh" << endl;
            }
            cout << res << endl;
        }
    }
    return 0;
}
