#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long arr[n],diff=1000000000;

        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        sort(arr, arr+n);
        for(int i=0;i<n;i++){
            long temp = abs((arr[i]-arr[i+1]));
            if(temp<diff){
                diff=temp;
            }
        }
        cout << diff << endl;
    }
}
