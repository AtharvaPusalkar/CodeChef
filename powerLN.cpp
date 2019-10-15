#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define eb emplace_back
using namespace std;

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
        string A, B;
        cin >> A >> B;
        ll base=0, power=0;
        for(int i=0; i<A.length(); i++)
            base = (base*10 + (A[i]-'0'))%MOD;
        for(int i=0; i<B.length(); i++)
            power = (power*10 + (B[i]-'0'))%(MOD-1);
        cout << calc(base, power) << "\n";
    }
    return 0;
}
