#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define eb emplace_back
using namespace std;

ull highestPowerof2(ull n){
    ll x;
    while(n){
        x=n;
        n=n&(n-1);
    }
    return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ull>digits(61,0);
    digits[0]=0;
    digits[1]=1;
    for(int i = 2; i <= 60; i++){
        digits[i] = (digits[i-1]+digits[i-2])%10;
    }
    int t;
    cin >> t;
    while(t--){
        ull N;
        cin >> N;
        if(N<=2){
            cout << digits[N-1] << "\n";
        }
        else if(N==3){
           cout << digits[N-2] << "\n";
        }else{
            ull closest = highestPowerof2(N);
            cout << digits[(closest-1)%60] << "\n";
        }
    }
    return 0;
}
