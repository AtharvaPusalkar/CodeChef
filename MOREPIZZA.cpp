#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 2e9
#define EPS 1e-9
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define endl "\n"
#define FOR(i,a,b) for (long long i = a; i < b; i++)
#define REV(i,a,b) for (long long i = a; i > b; i--)
#define mset(a, v) memset(a, v, sizeof(a))
typedef std::pair<int, int> pii;
typedef std::vector<long long> vi;
typedef std::vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

unordered_set<ll>sums;
ll res = 0;
map<ll,vi>mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("d_quite_big.in", "r", stdin);
    freopen("d_output.txt", "w", stdout);
    int M, N;
    cin >> M >> N;
    int S[N];
    FOR(i,0,N) {
        cin >> S[i];
    }
    sums.insert(res);
    mp[0].PB(-1);
    for(ll i=0;i<N;i++) {
        unordered_set<ll>new_sums;
        vi test = mp[res];
        for(auto sum:sums) {
            ll elem = S[i];
            vi curr_v = mp[sum];
            curr_v.PB(i);
            int curr = sum + elem;
            if (curr <= M) {
               new_sums.insert(curr);
                if (curr > res) {
                    res = curr;
                }
            }
            mp[curr] = curr_v;
        }
        for(auto i:new_sums) {
            sums.insert(i);
        }
    }
    vi res_v = mp[res];
    FOR(i,1,res_v.size()) {
        cout << res_v[i] << " ";
    }
    cout << endl;
    return 0;
}
