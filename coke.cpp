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
        ll N, M, K, L, R;
        cin >> N >> M >> K >> L >> R;
        ll C, P;
        ll min_cost= INT_MAX;
        for(ll i=0;i<N;i++){
            cin >> C >> P;
            if(C > K){
                C = max(K, C-M);
            }else if(C < K){
                C = min(K, C+M);
            }
            if(C>=L&&C<=R&&P<min_cost){
                min_cost = P;
            }
        }
        (min_cost==INT_MAX)? cout << "-1" << "\n":cout << min_cost << "\n";

    }
    return 0;
}
