#include <iostream>

using namespace std;

int main(){
    int n, k, c;
    cin >> n >> k;
    string s;
    int t[n];
    for(int i=0;i<n;i++){
        t[i] = 0;
    }
    int ct = 0;
    for(int i=0;i<k;i++){
        cin >> s;
        if(s!="CLOSEALL"){
            cin >> c;
            if(t[c-1]){
                t[c-1]= 0;
                ct--;
            }else{
                t[c-1] = 1;
                ct++;
            }
        }else{
            ct = 0;
            for(int i=0;i<n;i++){
                t[i] = 0;
            }
        }
        cout << ct << endl;
    }
}
