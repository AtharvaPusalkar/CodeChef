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

void change(ll *a,ll *b, ll n) {
    bool left = true;
    n = n%6;
    while(n--) {
        if(left) {
            *a = (*a)^(*b);
            left = false;
        }else {
            *b = (*a)^(*b);
            left = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll N, K;
        cin >> N >> K;
        ll A[N];
        for(ll i=0;i<N;i++) {
            cin >> A[i];
        }
        ll mul = 2*floor(K/N);
        ll rem = K%N;
        if(mul>0) {
            for(ll i=0;i<=(N-1)/2;i++) {
                if(i==N-i-1)
                    A[i] = 0;
                else
                    change(&A[i], &A[N-i-1], mul);
            }
        }
        for(ll i=0;i<rem;i++) {
            A[i] = A[i]^A[N-i-1];
        }

        for(ll i=0;i<N;i++) {
            cout << A[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
