#include <bits/stdc++.h>
#define MOD 1000000007
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define REP(i,a,b) for (long long i = a; i < b; i++)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll N, M, Q;
        cin >> N >> M >> Q;
        // ll rows[N], cols[M];
        // memset(rows, 0, sizeof(rows));
        // memset(cols, 0, sizeof(cols));
        bool mat[N][M];
        memset(mat, false, sizeof(mat));
        ll res = 0;
        while(Q--) {
            ll X, Y;
            cin >> X >> Y;
            // rows[X-1] = abs(M-rows[X-1]);
            // cols[Y-1] = abs(N-cols[Y-1]);
            for(ll i=0;i<M;i++) {
                mat[X-1][i] = !mat[X-1][i];
                if(mat[X-1][i]) {
                    res++;
                }else {
                    res--;
                }
            }
            for(ll i=0;i<N;i++) {
                mat[i][Y-1] = !mat[i][Y-1];
                if(mat[i][Y-1]) {
                    res++;
                }else {
                    res--;
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
