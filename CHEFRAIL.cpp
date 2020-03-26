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
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REV(i,a,b) for (int i = a; i > b; i--)
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
        int N, M;
        cin >> N >> M;
        int X[N], Y[M];
        FOR(i,0,N) {
            cin >> X[i];
        }
        FOR(i,0,M) {
            cin >> Y[i];
        }
        vector<pair<pair<int,int>,int>>x_dist, y_dist;
        FOR(i,0,N) {
            REV(j,N-1,i) {
                if(X[i]>0&&X[j]>0||X[i]<0&&X[j]<0) {
                    continue;
                }else {
                    int a = abs(X[i]-X[j])*abs(X[i]-X[j]);
                    x_dist.PB({{X[i],X[j]}, a});
                }
            }
        }
        FOR(i,0,M) {
            FOR(j,i+1,M) {
                if(Y[i]>0&&Y[j]>0||Y[i]<0&&Y[j]<0) {
                    continue;
                }else {
                    int a = abs(Y[i]-Y[j])*abs(Y[i]-Y[j]);
                    y_dist.PB({{Y[i],Y[j]}, a});
                }
            }
        }
        int res = 0;
        for(auto i:x_dist) {
            auto elem = i.F;
            int a = i.S;
            int X1 = elem.F;
            int X2 = elem.S;
            FOR(j,0,M) {
                int b = Y[j]*Y[j] + X1*X1;
                int c = Y[j]*Y[j] + X2*X2;
                if(check(a,b,c)) {
                    res++;
                }
            }
        }
        for(auto i:y_dist) {
            auto elem = i.F;
            int a = i.S;
            int Y1 = elem.F;
            int Y2 = elem.S;
            FOR(j,0,N) {
                int b = X[j]*X[j] + Y1*Y1;
                int c = X[j]*X[j] + Y2*Y2;
                if(check(a,b,c)) {
                    res++;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
