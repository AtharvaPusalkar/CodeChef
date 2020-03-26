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
    int t;
    cin >> t;
    while(t--) {
        int r0, c0;
        cin >> r0 >> c0;
        if(r0==c0&&(r0!=1&&c0!=1)) {
            cout << 19 << endl;
            cout << 1 << " " << 1 << endl;
        }else if(r0!=c0) {
            cout << 20 << endl;
            cout << (r0+c0)/2 << " " << (r0+c0)/2 << endl;
            cout << 1 << " " << 1 << endl;
        }else {
            cout << 18 << endl;
        }
        cout << 8 << " " << 8 << endl; // 1
        cout << 7 << " " << 7 << endl; // 2
        cout << 8 << " " << 6 << endl; // 3
        cout << 3 << " " << 1 << endl; // 4
        cout << 4 << " " << 2 << endl; // 5
        cout << 5 << " " << 1 << endl; // 6
        cout << 8 << " " << 4 << endl; // 7
        cout << 7 << " " << 3 << endl; // 8
        cout << 8 << " " << 2 << endl; // 9
        cout << 7 << " " << 1 << endl; // 10
        cout << 1 << " " << 7 << endl; // 11
        cout << 2 << " " << 8 << endl; // 12
        cout << 3 << " " << 7 << endl; // 13
        cout << 4 << " " << 8 << endl; // 14
        cout << 1 << " " << 5 << endl; // 15
        cout << 2 << " " << 4 << endl; // 16
        cout << 1 << " " << 3 << endl; // 17
        cout << 6 << " " << 8 << endl; // 18
    }
    return 0;
}
