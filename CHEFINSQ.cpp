#include <bits/stdc++.h>
#define MOD 1000000007
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define REP(a,b) for (long long i = a; i < b; i++)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll N, K;
        cin >> N >> K;
        int seq[N];
        REP(0, N){
            cin >> seq[i];
        }
        sort(seq, seq+N);
        int count = 1;
        int sum = accumulate(seq, seq+K, 0);
        REP(K,N){
            //cout << "cmp " << seq[i] << " and " << seq[i-1] << "\n";
            if(seq[i]==seq[i-1]){
                count++;
            }else{
                break;
            }
        }
        cout << count << "\n";
    }
    return 0;
}
