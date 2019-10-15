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
        int N;
        cin >> N;
        int F[N], S[N];
        for(int i=0;i<N;i++){
            F[i]=0;
            S[i]=0;
        }
        string s;
        int l_sum=0,r_sum=0;
        for(int i=0;i<N;i++){
            cin >> s;
            for(int j=0;j<N;j++){
                if(j<N/2 && s[j]=='1'){
                    F[i]++;
                    l_sum += 1;
                }else if(j>=N/2 && s[j]=='1'){
                    S[i]++;
                    r_sum += 1;
                }
            }
        }
        if(abs(l_sum-r_sum)==0){
            cout << "0" << "\n";
            continue;
        }
        int diff = abs(l_sum-r_sum);
        for(int i=0;i<N;i++){
            if(F[i]>S[i]){
                diff = min(diff, abs((l_sum-F[i]+S[i])-(r_sum+F[i]-S[i])));
            }else if(F[i]<S[i]){
                diff = min(diff, abs((l_sum+S[i]-F[i])-(r_sum-S[i]+F[i])));
            }
        }
        cout << diff << "\n";
    }
    return 0;
}
