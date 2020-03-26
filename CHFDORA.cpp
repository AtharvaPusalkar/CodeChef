#include <bits/stdc++.h>
#define MOD 1000000007
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define endl "\n"
#define FOR(i,a,b) for (long long i = a; i < b; i++)
#define REV(i,a,b) for (long long i = a; i > b; i--)
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
        ll N, M;
        cin >> N >> M;
        ll A[N][M];
        for(ll i=0;i<N;i++) {
            for(ll j=0;j<M;j++) {
                cin >> A[i][j];
            }
        }
        ll res = 0;
        for(ll i=0;i<N;i++) {
            for(ll j=0;j<M;j++) {
                ll cnt = 1;
                for(ll k=1;i-k>=0&&i+k<N&&j-k>=0&&j+k<M;k++) {
                    if(A[i+k][j]==A[i-k][j]&&A[i][j+k]==A[i][j-k]) {
                        cnt++;
                    }else {
                        break;
                    }
                }
                res += cnt;
            }
        }
        cout << res << endl;
    }
    return 0;
}
