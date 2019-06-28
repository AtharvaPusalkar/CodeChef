#include <iostream>

using namespace std;

bool find(int a[], int n, int find){
    for(int i=0;i<n;i++){
        if(a[i] == find){
            return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, a=0, b=0, i;
        int chef[1001], assist[1001];
        cin >> n;
        cin >> m;
        int done[m];
        for(i=0;i<m;i++){
            cin >> done[i];
        }
        int curr = 0;
        for(i=1;i<=n;i++){
            if(find(done, m, i)){
                continue;
            }
            if(curr%2 == 0){
                chef[a] = i;
                a++;
                curr++;
            }else{
                assist[b] = i;
                b++;
                curr++;
            }
        }
        for(i=0;i<a;i++){
            cout << chef[i] << " ";
        }
        cout << "\n";
        for(i=0;i<b;i++){
            cout << assist[i] << " ";
        }
    }
    return 0;
}
