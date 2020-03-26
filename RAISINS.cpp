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
#define FOR(i,a,b) for (long long i = a; i < b; i++)
#define REV(i,a,b) for (long long i = a; i > b; i--)
#define mset(a, v) memset(a, v, sizeof(a))
typedef std::pair<int, int> pii;
typedef std::vector<long long> vi;
typedef std::vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll W,H,R;
    cin >> W,H,R;
    ll X,Y;
    FOR(i,0,R) {
        cin >> X >> Y;
    }
    cout << 30 << " " << 30 << " " << 0 << endl;
    // FOR(i,0,30) {
    //     cout << 1 << " " << i+1 << endl;
    //     i++;
    // }
    // FOR(i,0,30) {
    //     cout << 2 << " " << i+1 << endl;
    //     i++;
    // }
    return 0;
}
