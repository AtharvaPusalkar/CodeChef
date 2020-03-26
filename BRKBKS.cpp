#include <bits/stdc++.h>
#define MOD 1000000007
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define endl "\n"
#define FOR(i,a,b) for (long long i = a; i < b; i++)
#define REV(i,a,b) for (long long i = a; i > b; i--)
typedef std::vector<long long > vi;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll s, W1, W2, W3, res;
        cin >> s >> W1 >> W2 >> W3;
        if(W1+W2+W3 <= s) {
            cout << 1 << endl;
        }else if (W1+W2 <= s||W2+W3 <= s) {
            cout << 2 << endl;
        }else {
            cout << 3 << endl;
        }
    }
    return 0;
}
