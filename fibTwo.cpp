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
    ll f[63];
    ll i,X=0,Y=0,P;
    f[0] = 0;
    for (i = 1; i <= 62; i++){
        P = ceil(sqrt(Y));
        if(P*P==Y){
            ++P;
        }
        X = P;
        Y += P*P;
        f[i] = X;
    }
    ll t;
    cin >> t;
    while(t--){
        ll X;
        cin >> X;
        for(i=0; i<=62;i++){
            if(f[i]>X){
                cout << i-1 << "\n";
                break;
            }
            if(f[i]==X){
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}
