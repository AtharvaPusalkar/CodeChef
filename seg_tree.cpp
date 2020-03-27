#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 2e9
#define EPS 1e-9
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define endl "\n"
#define FOR(i,a,b) for (long long i = a; i < b; i++)
#define REV(i,a,b) for (long long i = a; i >= b; i--)
#define mset(a, v) memset(a, v, sizeof(a))
typedef std::pair<int, int> pii;
typedef std::vector<long long> vi;
typedef std::vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n;
int b[100000];

// Segment tree template

struct segtree {
	ll a[1<<18] = {0}; // Stores range sum
	ll b[1<<18] = {0}; //Stores range max
	ll lazy[1<<18] = {0}; // Stores update values

	void app(int i, ll x) {
		a[i] += x;
		b[i] += x;
		lazy[i] += x;
	}

	void psh(int i) {
		app(2*i, lazy[i]); // Make pending changes
		app(2*i+1, lazy[i]);
		lazy[i]=0;
	}

	void upd(int l1, int r1, ll x, int i=1, int l2=0, int r2=n) {
		if(l1<=l2&&r2<=r1) {
			app(i, x); // current node is a leaf node
			return;
		}
		int m2=(l2+r2)/2;
		psh(i);
		if(l1<=m2)
			upd(l1, r1, x, 2*i, l2, m2);
		if(m2<r1)
			upd(l1, r1, x, 2*i+1, m2+1, r2);
		a[i] = a[2*i] + a[2*i+1];
		b[i] = max(b[2*i], b[2*i+1]);
	}

	void updIndex(int ind, int x, int i=1, int l2=0, int r2=n) {
		if(l2==r2) {
			app(i, x); // current node is a leaf node
			return;
		}
		int m2=(l2+r2)/2;
		psh(i);
		if(ind<=m2) {
			updIndex(ind, x, 2*i, l2, m2);
		}else {
			updIndex(ind, x, 2*i+1, m2+1, r2);
		}
		a[i] = a[2*i] + a[2*i+1];
		b[i] = max(b[2*i], b[2*i+1]);
	}

	ll range_max(int l1, int r1, int i=1, int l2=0, int r2=n) {
		if(l1<=l2&&r2<=r1)
			return b[i];
		int m2=(l2+r2)/2;
		psh(i);
		return max(l1<=m2?range_max(l1, r1, 2*i, l2, m2):-1e18, m2<r1?range_max(l1, r1, 2*i+1, m2+1, r2):-1e18);
	}

	ll range_sum(int l1, int r1, int i=1, int l2 = 0, int r2=n) {
		if(l1<=l2&&r1>=r2) {
			return a[i];
		}
		if (r2 < l1 || l2 > r1)
        	return 0;
		int m2 = (l2+r2)/2;
		psh(i);
		return range_sum(l1, r1, 2*i, l2, m2) + range_sum(l1, r1, 2*i+1, m2+1, r2);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
        int q;
        cin >> n >> q;
		for(int i=0; i<n; ++i)
			cin >> b[i];

		segtree sr, sl;
		//init segtrees
		int last = 0;
		for(int i=0; i<n; ++i) {
			// sr.upd(i+1, n, b[i]+last);
			// sl.upd(i+1, n, -(b[i]+last));
			sr.updIndex(i+1, last+b[i]);
			sl.updIndex(i+1, -(last+b[i]));
			last += b[i];
		}

		//queries
		for(int x, y; q--; ) {
			char qt;
			cin >> qt >> x >> y;
			if(qt=='Q') {
				//max suffix - min prefix
				cout << sr.range_max(y, n)+sl.range_max(0, x-1) << "\n";
			} else {
				sr.upd(x, n, y-b[x-1]);
				sl.upd(x, n, b[x-1]-y);
				b[x-1]=y;
			}
		}
	}
}
