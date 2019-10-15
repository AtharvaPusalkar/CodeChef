#include <bits/stdc++.h>
#define MOD 1000000007
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define REP(a,b) for (long long i = a; i < b; i++)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

void solve(int i, int sum, int cnt,
                int a[], int k, int* min_sum, int* min_cnt, int n)
{
    if (cnt > k || i > n){
        return;
    }
    if (cnt == k) {
		if (sum == *min_sum){
			(*min_cnt)++;
		}
		else if (sum < *min_sum){
			*min_sum = sum;
			*min_cnt = 1;
		}
    }
    cout << sum << " " << *min_sum << " " << *min_cnt << "\n";

    solve(i+1, sum, cnt, a, k, min_sum, min_cnt, n);

    solve(i+1, sum+a[i], cnt + 1, a, k, min_sum, min_cnt, n);
}

int main(){
    int a[] = {4, 3, 2, 7, 3};
    int n = 2;
	int min_sum = INT_MAX;
	int min_cnt = 0;
    solve(0, 0, 0, a, n, &min_sum, &min_cnt, sizeof(a)/sizeof(a[0]));
    cout << min_cnt << "\n";
    return 0;
}
