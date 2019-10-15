#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long n, p=0;
        cin >> n;
        long arr[n];
        for(long i=0;i<n;i++){
            cin >> arr[i];
        }
        sort(arr, arr+n);
        for(long i=0;i<n;i++){
            if(p>=arr[i]){
                p++;
            }else{
                break;
            }
        }
        cout << p << endl;
    }
    return 0;
}
