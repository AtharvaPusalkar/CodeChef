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
        ll N;
        cin >> N;
        ll P[N];
        
        for(ll i=0;i<N;i++) {
            cin >> P[i];
        }

        ll res = 0;
        for(ll i=N-1;i>=0;i--) {
            ll curr = P[i];
            bool flag = true;
            for(ll j=i-1;j>=max(0ll, i-5);j--) {
                if(P[j]<=curr) {
                    flag = false;
                    break;
                }
            }
            //if(flag) cout << P[i] << "\n";
            if(flag) res++;
        }
        cout << res << "\n";
    }
    return 0;
}
