#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long n, x, tot=0, cmp;
        cin >> n >> x;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            tot += a;
        }
        cmp = tot%x;
        if(cmp==0){
            cout << tot/x << endl;
        }
        else if(cmp >= x/2){
            cout << "-1" << endl;
        }
        else{
            cout << (tot-cmp)/x << endl;
        }
    }
    return 0;
}
