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
        ll N, M;
        cin >> N >> M;
        ll A[M];
        for(ll i=0;i<M;i++){
            cin >> A[i];
        }
        ll curr_max = INT_MIN;
        ll curr_min = INT_MAX;
        ll feed[N];
        memset(feed, 0, sizeof(feed));
        bool flag = true;
        for(ll i=0;i<M && flag;i++){
            feed[A[i]-1]++;
            curr_min = *(min_element(feed,feed+N));
                for(ll i=0;i<N;i++){
                    if(feed[i]<curr_min) {
                        curr_min = feed[i];
                    }
                    if(abs(feed[i]-curr_min)>1) {
                        flag = false;
                        break;
                    }
                }
        }
        (flag)? cout << "YES" << "\n":cout << "NO" << "\n";
    }
    return 0;
}
