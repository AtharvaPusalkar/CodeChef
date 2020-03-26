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
    ll N, Q;
    cin >> N >> Q;

    ll A[N];
    for(ll i=0;i<N;i++) {
        cin >> A[i];
    }

    ll cntI[N+1];
    ll contI[N];
    memset(cntI, 0, sizeof(contI));
    cntI[0] = 0;
    bool flag = false;

    for(ll i=0;i<N-1;i++) {
        if(A[i]<A[i+1]) {
            contI[i+1] = 1;
            if(flag == false) {
                cntI[i+1] = cntI[i]+1;
                flag = true;
            }else {
                cntI[i+1] = cntI[i];
            }
        }else if(flag == true) {
            cntI[i+1] = cntI[i];
            flag = false;
        }else {
            cntI[i+1] = cntI[i];
        }
    }
    cntI[N] = cntI[N-1];

    ll cntD[N+1];
    cntD[0] = 0;
    ll contD[N];
    memset(contD, 0, sizeof(contD));
    flag = false;

    for(ll i=0;i<N-1;i++) {
        if(A[i]>A[i+1]) {
            contD[i+1] = 1;
            if(flag == false) {
                cntD[i+1] = cntD[i]+1;
                flag = true;
            }else {
                cntD[i+1] = cntD[i];
            }
        }else if(flag == true) {
            cntD[i+1] = cntD[i];
            flag = false;
        }else {
            cntD[i+1] = cntD[i];
        }
    }
    cntD[N] = cntD[N-1];

    ll L, R;

    while(Q--) {
        cin >> L >> R;

        ll a = abs(cntI[R-1]-cntI[L-1]);
        ll b = abs(cntD[R-1]-cntD[L-1]);

        if(A[L-1]<A[L] && contI[L-1]==1) {
            a++;
        }
        if(A[L-1]>A[L] && contD[L-1]==1) {
            b++;
        }
        (a==b)? cout << "YES" << endl : cout << "NO" << endl;

    }
    return 0;
}
