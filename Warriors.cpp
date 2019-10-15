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
        ll N, Q, X;
        cin >> N >> Q;
        ll P[N];
        for(ll i=0;i<N;i++){
            cin >> P[i];
        }
        sort(P, P+N);
        while(Q--){
            cin >> X;
            ll count = 0;
            for(ll i=0;i<N;i++){
                if(X>P[i]){
                    count++;
                    X = 2*(X-P[i]);
                }else{
                    break;
                }
            }
            cout << count << "\n";
        }
    }
    return 0;
}
