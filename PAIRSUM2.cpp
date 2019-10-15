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
    while(t--){
        ll N, Q;
        cin >> N >> Q;
        ll B[N-1];
        for(ll i=0;i<N-1;i++){
            cin >> B[i];
        }
        while(Q--){
            ll a, b;
            cin >> a >> b;
            ll temp = max(a, b);
            a = min(a, b);
            b = temp;
            ll i=a,j=i+1;
            ll tot = 0;
            while(i<b){
                tot += B[i-1];
                i++;
                j++;
            }
            if(b-a==2){
                cout << "UNKNOWN" << "\n";
            }else if(b-a==1 && a == 1) {
                cout << B[a-1] << "\n";
            }
            else{
                j = a+1;
                while(j<b-1){
                     tot -= 2*B[j-1];
                     j++;
                }
                cout << tot << "\n";
            }
        }
    }
    return 0;
}
