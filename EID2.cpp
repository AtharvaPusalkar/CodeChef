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
        ll A[3];
        ll C[3];
        cin >> A[0] >> A[1] >> A[2] >> C[0] >> C[1] >> C[2];
        ll max_age = INT_MIN, max_money = INT_MIN;
        ll min_age = INT_MAX, min_money = INT_MAX;
        bool flag = false;
        for(int i=0;i<3;i++){
            if(A[i]>max_age){
                if(C[i]>max_money){
                    if(max_age != INT_MIN){
                        min_age = max_age;
                        min_money = max_money;
                    }
                    max_age = A[i];
                    max_money = C[i];
                }else{
                    flag = true;
                }
            }else if(A[i]==max_age){
                if(C[i]!=max_money){
                    flag = true;
                }
            }else if(A[i]<max_age && C[i]>max_money){
                flag = true;
            }else if(A[i]<min_age){
                if(C[i]<min_money){
                    if(min_age!=INT_MAX){
                       max_age = min_age;
                       max_money = min_money;
                    }
                    min_age = A[i];
                    min_money = C[i];
                }else{
                    flag = true;
                }
            }else if(A[i]==min_age){
                if(C[i]!=min_money){
                    flag = true;
                }
            }else if(A[i]>min_age&&C[i]<min_money){
                flag = true;
                break;
            }
        }
        (flag)? cout << "NOT FAIR" << "\n":cout << "FAIR" << "\n";
    }
    return 0;
}
