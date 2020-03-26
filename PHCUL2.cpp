#include <bits/stdc++.h>
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define endl "\n"
#define FOR(a, b, i) for (long long i = a; i < b; i++)
#define REV(a, b, i) for (long long i = b; i > a; i--)
#define pii pair<ll, ll>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll N, M, K, X, Y;
        cin >> X >> Y;
        cin >> N >> M >> K;
        ll A[N], B[N];
        ll C[M], D[M];
        ll E[K], F[K];
        for(ll i=0;i<N;i++) {
            cin >> A[i] >> B[i];
        }
        for(ll i=0;i<M;i++) {
            cin >> C[i] >> D[i];
        }
        for(ll i=0;i<K;i++) {
            cin >> E[i] >> F[i];
        }
        double dist = 20000.0;
        for(ll i=0;i<N;i++) {
            double f = pow(pow(A[i]-X,2)+pow(B[i]-Y,2),0.5);
            for(ll j=0;j<M;j++) {
                double s = f + pow(pow(C[j]-A[i],2)+pow(D[j]-B[i],2),0.5);
                for(ll k=0;k<K;k++) {
                    double t = s + pow(pow(E[k]-C[j],2)+pow(F[k]-D[j],2),0.5);
                    dist = min(dist, t);
                }
            }
        }
        for(ll i=0;i<M;i++) {
            double f = pow(pow(C[i]-X,2)+pow(D[i]-Y,2),0.5);
            for(ll j=0;j<N;j++) {
                double s = f + pow(pow(A[j]-C[i],2)+pow(B[j]-D[i],2),0.5);
                for(ll k=0;k<K;k++) {
                    double t = s + pow(pow(E[k]-A[j],2)+pow(F[k]-B[j],2),0.5);
                    dist = min(dist, t);
                }
            }
        }
        cout << std::setprecision(15) << dist << endl;
    }
    return 0;
}
