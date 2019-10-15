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
        ll N, Q;
        cin >> N >> Q;
        string s;
        cin >> s;
        while(Q--){
            ll L, R;
            cin >> L >> R;
            unordered_map<int, ll>mp;
            bool flag=false;
            for(ll i=L-1;i<=R-1;i++){
                if(mp[s[i]]){
                    mp[s[i]]++;
                }else{
                    mp[s[i]] = 1;
                }
                if(mp[s[i]]>=2){
                    flag = true;
                    break;
                }
            }
            (flag)? cout << "YES" << "\n":cout << "NO" << "\n";
        }
    }
    return 0;
}
