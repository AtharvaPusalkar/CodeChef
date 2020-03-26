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
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REV(i,a,b) for (int i = a; i > b; i--)
#define endl "\n"
#define mset(a, v) memset(a, v, sizeof(a))
typedef std::pair<int, int> pii;
typedef std::vector<long long> vi;
typedef std::vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

bool check(ll A, ll B, ll C) {
    if(A==B+C||B==A+C||C==A+B) {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int N, M, e;
        cin >> N >> M;
        int X[N], Y[M];
        vi Xv,Yv;
        unordered_map<ll,ll>mp_x;
        unordered_map<ll,ll>mp_y;
        for(int i=0;i<N;i++) {
            cin >> X[i];
            if(!mp_x[abs(X[i])]) {
                Xv.PB(abs(X[i]));
            }
            mp_x[abs(X[i])]++;
        }
        for(int i=0;i<M;i++) {
            cin >> Y[i];
            if(!mp_y[abs(Y[i])]) {
                Yv.PB(abs(Y[i]));
            }
            mp_y[abs(Y[i])]++;
        }
        ll res = 0;
        vector<pair<pair<int,int>,int>>x_dist, y_dist;
        FOR(i,0,N) {
            FOR(j,i+1,N) {
                int a = abs(X[i]-X[j])*abs(X[i]-X[j]);
                x_dist.PB({{X[i],X[j]}, a});
            }
        }
        FOR(i,0,M) {
            FOR(j,i+1,M) {
                int a = abs(Y[i]-Y[j])*abs(Y[i]-Y[j]);
                y_dist.PB({{Y[i],Y[j]}, a});
            }
        }
        for(auto i:x_dist) {
            auto elem = i.F;
            int a = i.S;
            int X1 = elem.F;
            int X2 = elem.S;
            FOR(j,0,Yv.size()) {
                int b = Yv[j]*Yv[j] + X1*X1;
                int c = Yv[j]*Yv[j] + X2*X2;
                if(check(a,b,c)) {
                    res += mp_y[Yv[j]];
                }
            }
        }
        for(auto i:y_dist) {
            auto elem = i.F;
            int a = i.S;
            int Y1 = elem.F;
            int Y2 = elem.S;
            FOR(j,0,Xv.size()) {
                int b = Xv[j]*Xv[j] + Y1*Y1;
                int c = Xv[j]*Xv[j] + Y2*Y2;
                if(check(a,b,c)) {
                    res += mp_x[Xv[j]];
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
