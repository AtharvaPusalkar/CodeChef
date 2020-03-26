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
        ll a=0,b=0;
        ll i=0;
        bool flag = false;
        ll res;
        while(i<2*N) {
            if(s[i]=='1') {
                a++;
            }
            if(abs(a-b)>N-i) {
                res = i+2;
                flag =true;
                break;
            }
            if(s[i+1]=='1') {
                b++;
            }
            if(abs(a-b)>N-i) {
                res = i+2;
                flag =true;
                break;
            }
            i+=2;
        }
        (flag)?cout << res << endl:cout << 2*N << endl;
    }
    return 0;
}
