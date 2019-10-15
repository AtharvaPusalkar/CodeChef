#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define eb emplace_back
using namespace std;

ll gcd(ll a,ll b){
    if(b==0){
    }    return a;
    return gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,F,e,res=0;
    cin>>N>>F;
    vector<ll>arr;
    vector<ll>factors;
    set<ll> s;
    for(ll i=0;i<N;i++){
        cin >> e;
        arr.eb(e);
    }
    factors.eb(F);
    for(ll i=2;i<sqrt(F);i++){
        if(F%i==0){
            factors.eb(i);
            if(F/i !=i){
                factors.eb(F/i);
            }
        }
    }
    for(ll i=0;i<arr.size();i++){
               s.insert(gcd(arr[i], F));
    }
    ll i=0;
    while(i<factors.size()){
        e = factors[i++];
        bool flag=true;
        for(auto n: s){
            if(n%e==0){
                flag=false;
            }
        }
        if(flag){
            res++;
        }
    }
    cout << res << "\n";
    return 0;
}
