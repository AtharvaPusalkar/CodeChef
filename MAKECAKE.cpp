#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 2e9
#define EPS 1e-9
#define MAX LLONG_MAX
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
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    ll A[N];
    FOR(i,0,N) {
        cin >> A[i];
    }
    unordered_map<ll,ll>DONE;
    unordered_map<ll,ll>PR;
    ll bottom=N+1;
    FOR(i,0,N) {
        PR[A[i]] = 1;
        if(A[i]==bottom-1) {
            queue<ll> Q;
            Q.push(A[i]);
            DONE[A[i]] = 1;
            REV(j,A[i]-1,-1) {
                if(PR[j]&&!DONE[j]) {
                    Q.push(j);
                    DONE[j] = 1;
                }else{
                    break;
                }
            }
            while(Q.size()) {
                cout << Q.front() << " ";
                if(Q.size()==1) {
                    bottom = Q.front();
                }
                Q.pop();
            }
            cout << endl;
        }else {
            cout << " " << endl;
        }
    }
    return 0;
}
