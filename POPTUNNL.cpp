#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 2e9
#define EPS 1e-9
#define MAX LLONG_MAX
#define FS first
#define SC second
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

int solve(string s, ll ind, ll *res, ll N, vector<string>S, ll steps, ll K, vector<ll>visited) {
    if(ind!=N-1&&steps<*res) {
        FOR(i,0,N) {
            if(s[i]=='1'&&(abs(i-ind)<=K)&&!visited[i]) {
                visited[i] = 1;
                solve(S[i], i, res, N, S,steps+1,K,visited);
            }
        }
    }else {
        *res = min(*res, steps);
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll K, N;
        cin >> N >> K;
        vector<string>S;
        ll last = 0;
        FOR(i,0,N) {
            string s;
            cin >> s;
            S.PB(s);
            if(s[N-1]=='0') {
                last++;
            }
        }
        ll res = MAX;
        bool flag = true;
        vector<ll>visited(N,0);
        if(last!=N) {
            solve(S[0], 0, &res, N, S, 0, K, visited);
        }
        (res==MAX)? cout << -1 << endl:cout << res << endl;
    }
    return 0;
}
