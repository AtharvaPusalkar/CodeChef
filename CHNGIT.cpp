#include <bits/stdc++.h>
#define MOD 1000000007
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define pii pair<ll, ll>
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
        ll N;
        cin >> N;
        ll A[N];
        unordered_map<ll,ll>mp;
        ll max_cnt = 0;
        ll max_n = LLONG_MAX;
        for(ll i=0;i<N;i++) {
            cin >> A[i];
            mp[A[i]]++;
            if(mp[A[i]]>max_cnt) {
                max_cnt = mp[A[i]];
                max_n = A[i];
            }
        }
        cout << N-max_cnt << endl;

    }
    return 0;
}