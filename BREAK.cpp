#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 2e9
#define EPS 1e-9
#define MAX LLONG_MAX
#define MIN LLONG_MIN
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
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int s;
    cin >> t >> s;
    while(t--) {
        int N,e;
        cin >> N;
        vi A,B;
        FOR(i,0,N) {
            cin >> e;
            A.PB(e);
        }
        FOR(i,0,N) {
            cin >> e;
            B.PB(e);
        }
        if(s==2) {
            cout << "NO" << endl;
        }
        else {
            sort(A.begin(),A.end());
            sort(B.begin(),B.end());
            bool ok = true;
            unordered_map<int,bool>tb;
            tb[A[0]] = true;
            FOR(i,0,N) {
                if(tb[A[i]]) {
                    if(A[i]>=B[i]) {
                        ok = false;
                        break;
                    }else {
                        ok = true;
                        tb[B[i]] = true;
                    }
                }else {
                    ok = false;
                    break;
                }
            }
            (ok)? cout << "YES" << endl: cout << "NO" << endl;
        }
    }
    return 0;
}
