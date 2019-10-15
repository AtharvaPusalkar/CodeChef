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
        ll N, M, Q, X, Y;
        cin >> N >> M >> Q;
        ll X_arr[N], Y_arr[M];
        memset(X_arr, 0, sizeof(X_arr));
        memset(Y_arr, 0, sizeof(Y_arr));
        while(Q--) {
            cin >> X >> Y;
            X_arr[X-1] = !X_arr[X-1];
            Y_arr[Y-1] = !Y_arr[Y-1];
        }
        ll even_X = 0;
        ll odd_X = 0;
        ll even_Y = 0;
        ll odd_Y = 0;
        for(ll i=0;i<N;i++) {
            if(X_arr[i]==1) {
                odd_X++;
            }else{
                even_X++;
            }
        }
        for(ll i=0;i<M;i++) {
            if(Y_arr[i]==1) {
                odd_Y++;
            }else{
                even_Y++;
            }
        }
        cout << (even_X*odd_Y)+(even_Y*odd_X) << "\n";
    }
    return 0;
}
