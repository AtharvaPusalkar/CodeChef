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
typedef std::vector<long long> vi;
typedef std::vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll tkts[] = {100, 75, 50, 25};
string movies[] = {"A", "B", "C", "D"};
ll times[] = {12, 3, 6, 9};
map<pair<string, ll>, ll> mp;

int solve(ll *profit, ll ind, map<string,bool>visited, vi path) {
    if(ind == 4) {
        ll curr = 0;
        // FOR(i,0,path.size()) {
        //     cout << path[i] << " ";
        // }
        // cout << endl;
        sort(path.rbegin(),path.rend());
        FOR(i,0,path.size()) {
            if(path[i]==0) {
                curr -= 100;
            }else {
                curr += tkts[i]*path[i];
            }
        }
        *profit = max(*profit, curr);
        //cout << "profit " << *profit << endl;
    }else {
        FOR(i,0,4) {
            if(!visited[movies[i]]) {
                visited[movies[i]] = true;
                path.PB(mp[{movies[i], times[ind]}]);
                solve(profit, ind+1, visited, path);
                visited[movies[i]] = false;
                path.pop_back();
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    ll total = 0;
    while(t--) {
        string movie;
        ll time;
        ll N;
        cin >> N;
        FOR(i,0,N) {
            cin >> movie >> time;
            mp[{movie, time}]++;
        }
        ll profit = MIN;
        vi path;
        map<string,bool>visited;
        // for(auto i:movies) {
        //     for(auto j:times) {
        //         cout << mp[{i,j}] << " ";
        //     }
        //     cout << endl;
        // }
        solve(&profit, 0, visited, path);
        cout << profit << endl;
        total += profit;
        mp.clear();
    }
    cout << total << endl;
    return 0;
}
