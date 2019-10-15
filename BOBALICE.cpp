#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define eb emplace_back
using namespace std;

ll count_primes(ll N){
    ll count = 0;
    bool arr[N+1];
    //memset(arr, false, sizeof(arr));
    for(ll i = 2;i<=N;i++){
        if(arr[i] == false){
            count++;
            for(ll j = i; j <= N; j += i){
                arr[j] = true;
            }
        }
    }
    return count;
    }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll N;
        cin >> N;
        (count_primes(N)%2==0)? cout << "Bob" << "\n":cout << "Alice" << "\n";
    }
    return 0;
}
