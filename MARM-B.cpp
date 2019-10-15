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
        ll N, K, ind;
        cin >> N >> K;
        ll A[N];
        for(ll i=0;i<N;i++) {
            cin >> A[i];
        }
        for(ll i=0;i<K;i++) {
            ind = i%N;
            A[ind] = A[ind]^A[N-ind-1];
        }
        for(ll i=0;i<N;i++) {
            cout << A[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
