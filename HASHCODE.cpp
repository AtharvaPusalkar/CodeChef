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

vi solve(ll M, vi arr, ll *ans) {
    vi combo;
    vi curr_combo;
    ll res = 0;
    ll i = arr.size(); // i = N
    bool flag = true;
    bool done = false;
    while(i>=0&&flag) {
        ll ind = i;
        ll curr = 0;
        while(ind>=0&&!done) {
            ll elem = arr[ind];
            //Greedy approach; get as many elems as possible
            if(curr+elem<M) {
                curr += elem;
                curr_combo.PB(ind);
            } else if (curr+elem==M) {
                curr += elem;
                curr_combo.PB(ind);
                flag = false;
                done = true;
            }
            ind--;
        }
        if(res<curr) {
            //update result and array
            res = curr;
            combo = curr_combo;
        }
        if(combo.size()==arr.size()) {
                flag = false; // avoid taking more slices
        }
        i--;
        curr_combo.clear();
    }
    *ans = res;
    return combo;
}

int main() {
    freopen("e_also_big.txt", "r", stdin);
    freopen("e_output.txt", "w", stdout);
    int M, N;
    cin >> M >> N;
    vi s;
    FOR(i,0,N) {
        ll e;
        cin >> e;
        s.PB(e);
    }
    ll res = 0;
    vi res_arr = solve(M,s,&res);
    cout << res_arr.size() << endl;
    REV(i,res_arr.size()-1,-1) {
        cout << res_arr[i] << " ";
    }
    cout << endl;
    return 0;
}
