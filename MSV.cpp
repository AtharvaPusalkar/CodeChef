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
        ll max_count = 0;
        cin >> N;
        ll A[N];
        unordered_map<ll, ll>cnt;
        for(ll i=0;i<N;i++) {
            cin >> A[i];
        }
        for(ll i=0;i<N;i++) {
            max_count = max(max_count, cnt[A[i]]);
            for (int j=1; j*j<=A[i]; j++) {
                if (A[i]%j == 0) {
                    cnt[j]++;
                    if (j*j!=A[i]) {
                        cnt[A[i]/j]++;
                    }
                }
            }
        }
        cout << max_count << "\n";
    }
    return 0;
}
