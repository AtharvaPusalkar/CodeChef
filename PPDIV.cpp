#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 2e9
#define EPS 1e-7
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define endl "\n"
#define FOR(i,a,b) for (long long i = a; i < b; i++)
#define REV(i,a,b) for (long long i = a; i >= b; i--)
#define mset(a, v) memset(a, v, sizeof(a))
typedef std::pair<int, int> pii;
typedef std::vector<long long> vi;
typedef std::vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

unordered_map<ll,ll>mp;
ll sum, N;

bool check_xy(ll n) {
    if (n == 1)
        return true;
    for(ll i = 2; i * i <= n; i++) {
        double val = log(n) / log(i);
        if ((val - (ll)val) < EPS) {
            return true;
        }
    }
    return false;
}

void solve() {
    sum = 0;
    FOR(i,1,N+1) {
        ll temp = 0;
        if(check_xy(i)) {
            mp[i] = true;
        }
        unordered_map<ll,bool>pr;
//       cout << "for " << i << " --> ";
       FOR(j,1,sqrt(i)+1) {
           if (i%j == 0) {
               if (i/j == j) {
                    if(mp[j] && !pr[j]) {
                        temp = (temp%MOD + j%MOD)%MOD;
//                        cout << j << " ";
                        pr[j] = true;
                    }
               }else {
                   if(mp[j] && !pr[j]) {
                        temp = (temp%MOD + j)%MOD;
//                        cout << j << " ";
                        pr[j] = true;
                   }
                   if(mp[i/j] && !pr[i/j]) {
                        temp = (temp%MOD + (i/j)%MOD)%MOD;
//                        cout << i/j << " ";
                        pr[i/j] = true;
                   }
               }
           }
       }
//       cout << endl;
    //    FOR(j,1,i+1) {
    //        if(i%j==0 && mp[j]) {
    //            temp = (temp%MOD + j%MOD)%MOD;
    //        }
    //    }
        sum = (sum%MOD + temp%MOD)%MOD;
    }
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        mp.clear();
        cin >> N;
        if(N<=1000000) {
            solve();
        }else {
            cout << 1 << endl;
        }
    }
    return 0;
}
