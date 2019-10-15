#include <bits/stdc++.h>
#define MOD 1000000007
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define REP(i,a,b) for (long long i = a; i < b; i++)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll N;
        cin >> N;
        ll arr[N];
        ll sum = 0;
        for(ll i=0;i<N;i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        double res = sum*1.0/N;
        (((ll)res)*N == sum)? cout << (ll)res << "\n": cout << (ll)res + 1 << "\n";
        //cout << ceil(res) << "\n";
    }
    return 0;
}

