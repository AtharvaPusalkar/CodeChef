#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        string s, r;
        cin >> s >> r;
        ll s_count_1 = 0, s_count_0 = 0;
        ll r_count_1 = 0, r_count_0 = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                s_count_1++;
            }
            if(s[i]=='0'){
                s_count_0++;
            }
            if(r[i]=='1'){
                r_count_1++;
            }
            if(r[i]=='0'){
                r_count_0++;
            }
        }
        if(s_count_0==r_count_0 && s_count_1==r_count_1){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
    return 0;
}