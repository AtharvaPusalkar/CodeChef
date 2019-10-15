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
        ll N, K, C=0;
        cin >> N >> K;
        if(K==1){
            cout << "NO" << "\n";
            continue   ;
        }
        else if(N==K){
            cout << "YES" << "\n";
        }else{
            if((N/K)%K>0){
                cout << "YES" << "\n";
            }else{
                cout << "NO" << "\n";
            }
        }
    }
    return 0;
}
