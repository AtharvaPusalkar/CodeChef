#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define eb emplace_back
using namespace std;

ll factorial(ll n){ 
    ll res = 1, i; 
    for (i = 2; i <= n; i++) 
        res *= i; 
    return res;
}

ll calc(ll x, ll n){
    ll result = 1;
    while (n) {
        if (n & 1)
            result = result * x % MOD;
        n = n / 2;
        x = x * x % MOD;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll N, M;
        cin >> N >> M;
        ll num = factorial(N+M-1)%MOD;
        ll den = factorial(M-1)*factorial(N)%MOD;
        den = calc(den, MOD-2)%MOD;
        cout << (num*den)%MOD << "\n";
    }
    return 0;
}