#include <bits/stdc++.h>
#define MOD 1000000007
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define endl "\n"
#define FOR(a,b) for (long long i = a; i < b; i++)
#define REV(a,b) for (long long i = b; i > a; i--)
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
        ll curr_x = X, curr_y = Y;
        ll x_1, x_2, y_1, y_2;
        double dist = 0;
        double curr_min_1 = DBL_MAX;

        for(ll i=0;i<N;i++) {
            double curr = pow(pow(A[i]-curr_x,2)+pow(B[i]-curr_y,2),0.5);
            if(curr<curr_min_1) {
                curr_min_1 = curr;
                x_1 = A[i];
                y_1 = B[i];
            }
        }
        double curr_min_2 = DBL_MAX;
        for(ll i=0;i<M;i++) {
            double curr = pow(pow(C[i]-curr_x,2)+pow(D[i]-curr_y,2),0.5);
            if(curr<curr_min_2) {
                curr_min_2 = curr;
                x_2 = A[i];
                y_2 = B[i];
            }
        }

        if(curr_min_1<curr_min_2) {
            dist += curr_min_1;
            double curr_min = DBL_MAX;
            curr_x = x_1;
            curr_y = y_1;
            for(ll i=0;i<M;i++) {
                double curr = pow(pow(C[i]-curr_x,2)+pow(D[i]-curr_y,2),0.5);
                if(curr<curr_min) {
                    curr_min = curr;
                    x_1 = C[i];
                    y_1 = D[i];
                }
            }
            dist += curr_min;
            curr_x = x_1;
            curr_y = y_1;
            curr_min = DBL_MAX;
            for(ll i=0;i<K;i++) {
                double curr = pow(pow(E[i]-curr_x,2)+pow(F[i]-curr_y,2),0.5);
                if(curr<curr_min) {
                    curr_min = curr;
                }
            }
            dist+= curr_min;
        }else {
            dist += curr_min_2;
            double curr_min = DBL_MAX;
            curr_x = x_2;
            curr_y = y_2;
            for(ll i=0;i<N;i++) {
                double curr = pow(pow(A[i]-curr_x,2)+pow(B[i]-curr_y,2),0.5);
                if(curr<curr_min) {
                    curr_min = curr;
                    x_2 = A[i];
                    y_2 = B[i];
                }
            }
            dist += curr_min;
            curr_x = x_2;
            curr_y = y_2;
            curr_min = DBL_MAX;
            for(ll i=0;i<K;i++) {
                double curr = pow(pow(E[i]-curr_x,2)+pow(F[i]-curr_y,2),0.5);
                if(curr<curr_min) {
                    curr_min = curr;
                }
            }
            dist+= curr_min;
        }
        cout << std::setprecision(11) << dist << endl;
    }
    return 0;
}
