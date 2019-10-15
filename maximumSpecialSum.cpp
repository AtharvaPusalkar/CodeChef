#include <iostream>
#include <numeric>
using namespace std;

int arraySum(long int a[],long int n)
{
    long int initial_sum  = 0;
    return accumulate(a, a+n, initial_sum);
}

bool isPrime(long int num){
    bool flag=true;
    for(long int i = 2; i <= num / 2; i++) {
       if(num % i == 0) {
          flag = false;
          break;
       }
    }
    return flag;
}

int testSpecial(long int a[],long int n,long int k ,long int s){
    long int prime_count=0, i, sum;
    sum = arraySum(a, n);
    for(i=0;i<n;i++){
        if(isPrime(a[i])){
            prime_count++;
        }
    }
    return sum * (k - prime_count*s);
}

int main() {
	long int n, s,i, j, k, res=0, value, ind, foo;
    cin >> n;
    cin >> k;
    cin >> s;
    long int arr[n], curr[n];
    for(i=0;i<n;i++){
        cin >> arr[i];
    }
    for(i=0;i<n;i++){
        ind = 0;
        curr[ind] = arr[i];
        ind++;
        for(j=0;j<n;j++){
            if(i!=j){
                curr[ind] = arr[j];
                ind++;
                value = testSpecial(curr, ind, k, s);
                if(value > res){
                    res = value;
                }
            }
        }
    }
    cout << res;
    return 0;
}
