#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100009;
int n, m, x, y, z;
string str;
int csum[maxn];
int main()
{
//    freopen("input05.txt", "r", stdin);
//    freopen("output05.txt", "w", stdout);

	int t, cs = 1;
	cin >> t;
	if(t < 1 || t > 10) assert(false);

	while(t--){

	    cin >> str;
	    memset(csum, 0, sizeof(csum));
	    if(str.size() > 100000) assert(false);
	    int n = str.size();
	    str = " " + str;

	    for(int i = 1; i <= n; i++){
	        if(str[i] == '0') csum[i] = csum[i - 1];
	        else if(str[i] == '1') csum[i] = csum[i - 1] + 1;
	        else{
	            assert(false);
	        }
	    }
	    int ans = 0;

	    for(int i = 1; ; i++){

	        int len = i * i + i;

	        if(len > n) break;

	        for(int j = 1; j <= n - len + 1; j++){

	            long long cnt1 = csum[j + len - 1] - csum[j - 1];
	            long long cnt0 = len - cnt1;

	            if(cnt0 == cnt1 * cnt1) ans++;

	        }

	    }

	    printf("%d\n", ans);
	}

	return 0;
}
