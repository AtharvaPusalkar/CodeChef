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
#define FOR(i,a,b) for (long long i = a; i < b; i++)
#define REV(i,a,b) for (long long i = a; i > b; i--)
#define mset(a, v) memset(a, v, sizeof(a))
typedef std::pair<int, int> pii;
typedef std::vector<long long> vi;
typedef std::vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll get_count(ll A, ll B) {
    return (A-(A%B))/B + 1;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll N, P;
        cin >> N >> P;
        ll D[N], arr[N];
        FOR(i,0,N) {
            cin >> D[i];
            arr[i] = D[i];
        }
        ll curr = 0;
        ll ind = 0;
        sort(arr,arr+N,greater<ll>());
        bool flag = true;
        unordered_map<ll,ll>mp;
        while(curr<P&&flag&&ind<=N-1) {
            if((P-curr)>arr[ind]) {
                if((P-curr)%arr[ind]==0) {
                    if(ind==N-1) {
                        flag = false;
                    }
                    ll mul = ((P-curr)/arr[ind]) - 1;
                    curr += arr[ind]*mul;
                    mp[arr[ind]] += mul;
                    ind++;
                }else{
                    ll mul = (P-curr)/arr[ind];
                    curr += arr[ind]*mul;
                    mp[arr[ind]] += mul;
                }
            }else if((P-curr)<arr[ind]) {
                curr += arr[ind];
                mp[arr[ind]]++;
            }else {
                if(ind!=N-1) {
                    ind++;
                }else {
                    flag = false;
                }
            }
        }
        if(!flag) {
            cout << "NO" << endl;
        }else {
            cout << "YES";
            FOR(i,0,N) {
                cout << " " << mp[D[i]];
            }
            cout << endl;
        }
    }
    return 0;
}
