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
        ll N;
        cin >> N;
        ll A=0, B=0;
        while(N--){
            ll cnd;
            ll scr_A, scr_B;
            cin >> cnd >> scr_A >> scr_B;
            bool flag = true;
            if(cnd==1) {
                A = scr_A;
                B = scr_B;
                flag = true;
                cout << "YES" << "\n";
            }else{
                if(scr_A==scr_B){
                    A = scr_A;
                    B = scr_B;
                    flag = true;
                    cout << "YES" << "\n";
                }
                else if(A>B && flag) {
                    if(A > min(scr_A, scr_B)){
                        A = max(scr_A, scr_B);
                        B = min(scr_A, scr_B);
                        flag = true;
                        cout << "YES" << "\n";
                    }else{
                        flag = false;
                        cout << "NO" << "\n";
                    }
                }
                else if(B>A && flag) {
                    if(B>min(scr_A, scr_B)) {
                        A = min(scr_A, scr_B);
                        B = max(scr_A, scr_B);
                        cout << "YES" << "\n";
                        flag = true;
                    }else{
                        flag = false;
                        cout << "NO" << "\n";
                    }
                }else {
                    flag = false;
                    cout << "NO" << "\n";
                }
            }
        }
    }
    return 0;
}
