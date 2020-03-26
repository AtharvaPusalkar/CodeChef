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
        ll N;
        cin >> N;
        string s;
        cin >> s;
        ll x = 0, y = 0;
        char last = ' ';
        for(auto i:s) {
            if(i=='U' && last!='U' && last !='D') {
                y++;
                last = 'U';
            }else if(i=='L' && last != 'L' && last != 'R') {
                x--;
                last = 'L';
            }else if(i=='R' && last !='R' && last != 'L') {
                x++;
                last = 'R';
            }else if(i=='D' && last != 'D' && last != 'U') {
                y--;
                last = 'D';
            }
        }
        cout << x << " " << y << endl;
    }
    return 0;
}
