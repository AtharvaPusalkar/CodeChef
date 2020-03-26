#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cerr << #x " = " << (x) << endl;
#define P(x) cerr << #x << endl;
#define int long long
typedef pair<int, int> pii;
const int mod = 1000000007;

map<pair<string, int>, int> mp;
set<string> st;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);

    int t;
	cin >> t;
	while(t --)
	{
		mp.clear();
		st.clear();
		int n;
		cin >> n;
		for(int i = 0; i < n; ++ i)
		{
			string w;
			int b;
			cin >> w >> b;
			++ mp[{w, b}];
			st.insert(w);
		}
		int cnt = 0;
		for(auto temp : st)
		{
			cnt += max((int)mp[{temp, 0LL}], (int)mp[{temp, 1LL}]);
		}
		cout << cnt << '\n';
	}


    return 0;
}
