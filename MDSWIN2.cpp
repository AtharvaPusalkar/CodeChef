#include <bits/stdc++.h>
#define MOD 998244353
#define INF 2e9
#define EPS 1e-9
#define N 100000
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

ll factNumInverse[N + 1];

ll natNumInverse[N + 1];

ll fact[N + 1];

int InverseofNumber(int p) {
    natNumInverse[0] = natNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        natNumInverse[i] = natNumInverse[p % i] * (p - p / i) % p;
    return 0;
}

int InverseofFactorial(int p) {
    factNumInverse[0] = factNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        factNumInverse[i] = (natNumInverse[i] * factNumInverse[i - 1]) % p;
    return 0;
}

int factorial(int p) {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
    return 0;
}

int compute(int n, int R, int p) {
    int res = ((fact[n] * factNumInverse[R]) % p * factNumInverse[n - R]) % p;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    InverseofNumber(MOD);
    InverseofFactorial(MOD);
    factorial(MOD);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int A[n];
        FOR(i,0,n) {
            cin >> A[i];
        }
        int Q;
        cin >> Q;
        while(Q--) {
            int L, R;
            cin >> L >> R;
            ll res = 0;
            unordered_map<int,int>mp;
            FOR(i,L-1,R) {
                mp[A[i]]++;
            }
            //cout << "Map size = " << mp.size() << endl;
            ll one = 0;
            ll n_one = 0;
            for(auto i:mp) {
                if(i.S>1) {
                    n_one++;
                }else {
                    one++;
                }
            }
            if(mp.size()==1) {
                cout << 1 << endl;
            }else if(n_one==0) {
                if(one%2==1) {
                    cout << one << endl;
                }else {
                    cout << 0 << endl;
                }
            }else if(n_one==1) {
                if(mp.size()%2==0) {
                    for(auto i:mp) {
                        if(i.S>1) {
                            res  = (res%MOD + compute(i.S, i.S-1, MOD))%MOD;
                        }
                    }
                    cout << res << endl;
                }else {
                    cout << 1 << endl;
                }
            }else {
                if(mp.size()%2==0) {
                    for(auto i:mp) {
                        if(i.S==2) {
                            res = (res%MOD + compute(i.S, 1, MOD))%MOD;
                        }else if(i.S>2) {
                            for(int j= 1;j<=i.S-2;j++) {
                                res  = (res%MOD + compute(i.S,j,MOD))%MOD;
                            }
                        }
                    }
                }else {
                    cout << 0 << endl;
                }
            }
        }
    }
    return 0;
}
