#include <bits/stdc++.h>
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define FOR(i,a,b) for (long long i = a; i < b; i++)
#define REV(i,a,b) for (long long i = a; i > b; i--)
typedef std::vector<long long> vi;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll N, S, A, B, C, D, E;
        cin >> N;
        ll temp = ceil(pow(10, N));
        S = 2 * temp;
        cin >> A;
        S += A;
        cout << S << "\n" <<flush;
        cin >> B;
        C = temp-B;
        cout << C << "\n" << flush;
        cin >> D;
        E = temp-D;
        cout << E << "\n" << flush;
        int flag;
        cin >> flag;
        if(flag==-1) {
            break;
        }
    }
    return 0;
}
