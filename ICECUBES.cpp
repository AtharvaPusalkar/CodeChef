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
    ll s[N];
    FOR(i,0,N) {
        cin >> s[i];
    }
    sort(s,s+N);
    ll res = 0;
    ll curr = 0;
    ll DONE[N];
    mset(DONE,0);
    FOR(i,0,N) {
        if(!DONE[i]) {
            curr = 1;
            DONE[i] = 1;
            ll last = s[i];
            FOR(j,0,N) {
                if(!DONE[j]&&s[i]<s[j]) {
                    DONE[j] = 1;
                    curr++;
                    last = s[j];
                    if(curr==3) {
                        res++;
                        curr=0;
                        break;
                    }
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}
