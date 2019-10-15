#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define eb emplace_back
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll XOR[n], arr[n];

        for(ll i=0;i<n;i++){
            cin >> arr[i];
        }
        ll ans = 0;

        ll* xorArr = new ll[n];

        unordered_map<ll, ll> mp;
        xorArr[0] = arr[0];

        for (ll i = 1; i < n; i++)
            xorArr[i] = xorArr[i - 1] ^ arr[i];

        for (ll i = 0; i < n; i++) {
            ll tmp = 0 ^ xorArr[i];
            ans = ans + ((ll)mp[tmp]);
            if (xorArr[i] == 0)
                ans += i;
            mp[xorArr[i]]++;
        }

        cout << ans << "\n";
    }
    return 0;
}
