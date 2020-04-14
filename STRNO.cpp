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
#define FOR(i,a,b) for (long long i = a; i < b; i+=2)
#define REV(i,a,b) for (long long i = a; i >= b; i--)
#define mset(a, v) memset(a, v, sizeof(a))
typedef std::pair<int, int> pii;
typedef std::vector<long long> vi;
typedef std::vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int count_prime_div(int n) {
    unordered_map<int,int>mp;

    while (n % 2 == 0) {
        mp[2]++;
        n = n/2;
    }

    FOR(i,3,sqrt(n)+1) {
        while (n % i == 0) {
            mp[i]++;
            n = n/i;
        }
    }

   if (n > 2) {
        mp[n]++;
   }

    int res = 0;
    for(auto e:mp) {
        if(e.S != 0) {
            res += e.S;
        }
    }
    return res;
}

void solve() {
    int X, K, res;
    cin >> X >> K;
    res = count_prime_div(X);
    if(res==0)
        res++;
    if(X==1){
        cout<< 0 << endl;
    }else if(K<=res){
        //cout << "K = " << K << " res = " << res << endl;
        cout<< 1 << endl;
    }else {
        cout<< 0 << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
