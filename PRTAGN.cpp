#include <bits/stdc++.h>
using namespace std;

bool Parity(unsigned long n)
{
    bool parity = 0;
    while (n)
    {
        parity = !parity;
        n     = n & (n - 1);
    }
    return parity;
}

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        long Q, X, E, O, n;
        set<long>S;
        cin >> Q;
        while(Q--){
            cin >> X;
            if(S.find(X)!=S.end()) {
                for(auto i = S.begin();i != S.end();i++){
                    if(*i != X){
                        S.insert(*i^X);
                    }
                }
            }
            E=0;
            O=0;
            for(auto i=S.begin();i != S.end();i++){
                if(Parity(*i)){
                    O += 1;
                }else{
                    E += 1;
                }
            }
            cout << E << " " << O << endl;
        }
    }
}
