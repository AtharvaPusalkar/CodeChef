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
        ll A[N], sorted[N];
        map<ll, ll>ind;
        for(ll i=0;i<N;i++) {
            cin >> A[i];
            sorted[i] = A[i];
            ind[A[i]] = max(ind[A[i]], i);
        }
        ll max_count = 0;
        ll curr;
        sort(sorted, sorted+N);
        for(ll i=0;i<N-1&&N-i-1>max_count;i++) {
            ll comp = ind[sorted[i]];
            if(sorted[i]!=sorted[i+1]&&comp>max_count-1){
            curr = 0;
            for(ll j=comp-1;j>=0;j--) {
                if(A[j]%A[comp]==0)
                    curr++;
            }
            max_count = max(max_count, curr);
            }
        }
        cout << max_count << "\n";
    }
    return 0;
}
