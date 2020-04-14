#include <bits/stdc++.h>
#define MOD 998244353
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

unordered_map<ll,ll>exp_0;
unordered_map<ll,ll>exp_1;
unordered_map<ll,ll>exp_a;
unordered_map<ll,ll>exp_A;

ll cnt = 1000;

ll pow_mod(ll b, int p) { // Modular exponentiation template
	ll ans=1;
	for(; p; b = b*b%MOD, p/=2)
		if(p&1)
			ans = ans * b%MOD;
	return ans;
}

void AND(ll l_0, ll l_1, ll l_a, ll l_A, ll r_0, ll r_1, ll r_a, ll r_A) {
    ll prob_0, prob_1, prob_a, prob_A;
    prob_0 = ((l_0%MOD * r_0%MOD)%MOD + (l_0%MOD * r_1%MOD)%MOD + (l_1%MOD * r_0%MOD)%MOD + (l_a%MOD * r_0%MOD)%MOD + (l_0%MOD * r_a%MOD)%MOD + (l_A%MOD * r_0%MOD)%MOD + (l_0%MOD * r_A%MOD)%MOD + (l_A%MOD * r_a%MOD)%MOD + (l_a%MOD * r_A%MOD)%MOD)%MOD;
    prob_1 = (l_1%MOD * r_1%MOD)%MOD;
    prob_a = ((l_a%MOD * r_a%MOD)%MOD + (l_a%MOD * r_1%MOD)%MOD + (l_1%MOD * r_a%MOD)%MOD)%MOD;
    prob_A = ((l_A%MOD * r_A%MOD)%MOD + (l_A%MOD * r_1%MOD)%MOD + (l_1%MOD * r_A%MOD)%MOD)%MOD;
//    cout << l_0 << " " << l_1 << " " << l_a << " " << l_A << " " << r_0 << " " << r_1 << " " << r_a << " " << r_A << endl;
//    cout << prob_0 << " " << prob_1 << " " << prob_a << " " << prob_A << endl;
    exp_0[cnt] = prob_0;
    exp_1[cnt] = prob_1;
    exp_a[cnt] = prob_a;
    exp_A[cnt] = prob_A;
}

void OR(ll l_0, ll l_1, ll l_a, ll l_A, ll r_0, ll r_1, ll r_a, ll r_A) {
    ll prob_0, prob_1, prob_a, prob_A;
    prob_0 = (l_0%MOD * r_0%MOD)%MOD;
    prob_1 = ((l_0%MOD * r_1%MOD)%MOD + (l_1%MOD * r_0%MOD)%MOD + (l_1%MOD * r_1%MOD)%MOD + (l_a%MOD * r_1%MOD)%MOD + (l_1%MOD * r_a%MOD)%MOD + (l_A%MOD * r_1%MOD)%MOD + (l_1%MOD * r_A%MOD)%MOD + (l_A%MOD * r_a%MOD)%MOD + (l_a%MOD * r_A%MOD)%MOD)%MOD;
    prob_a = ((l_a%MOD * r_0%MOD)%MOD + (l_0%MOD * r_a%MOD)%MOD + (l_a%MOD * r_a%MOD)%MOD)%MOD;
    prob_A = ((l_A%MOD * r_0%MOD)%MOD + (l_0%MOD * r_A%MOD)%MOD + (l_A%MOD * r_A%MOD)%MOD)%MOD;
    exp_0[cnt] = prob_0;
    exp_1[cnt] = prob_1;
    exp_a[cnt] = prob_a;
    exp_A[cnt] = prob_A;
}

void XOR(ll l_0, ll l_1, ll l_a, ll l_A, ll r_0, ll r_1, ll r_a, ll r_A) {
    ll prob_0, prob_1, prob_a, prob_A;
    prob_0 = ((l_0%MOD * r_0%MOD)%MOD + (l_1%MOD * r_1%MOD)%MOD + (l_a%MOD * r_a%MOD)%MOD + (l_A%MOD * r_A%MOD)%MOD)%MOD;
    prob_1 = ((l_0%MOD * r_1%MOD)%MOD + (l_1%MOD * r_0%MOD)%MOD + (l_a%MOD * r_A%MOD)%MOD + (l_A%MOD * r_a%MOD)%MOD)%MOD;
    prob_a = ((l_a%MOD * r_0%MOD)%MOD + (l_0%MOD * r_a%MOD)%MOD + (l_A%MOD * r_1%MOD)%MOD + (l_1%MOD * r_A%MOD)%MOD)%MOD;
    prob_A = ((l_A%MOD * r_0%MOD)%MOD + (l_0%MOD * r_A%MOD)%MOD + (l_a%MOD * r_1%MOD)%MOD + (l_1%MOD * r_a%MOD)%MOD)%MOD;
    exp_0[cnt] = prob_0;
    exp_1[cnt] = prob_1;
    exp_a[cnt] = prob_a;
    exp_A[cnt] = prob_A;
}

void solve(string exp) {
    stack<ll>upd_exp;

    FOR(i,0,exp.length()) {
        if (exp[i] == ')') {
            vector<ll> curr;
            while (upd_exp.top() != (ll)'(') {
                curr.push_back(upd_exp.top());
                upd_exp.pop();
            }
            upd_exp.pop();
            if(curr.size()==1) {
                upd_exp.push((ll)'#');
            }
            if(curr.size() == 3) {
                if(curr[1]==(ll)'&') {
//                    cout << curr[0] << "&" << curr[2] << " --> ";
                    AND(exp_0[curr[0]], exp_1[curr[0]], exp_a[curr[0]], exp_A[curr[0]], exp_0[curr[2]], exp_1[curr[2]], exp_a[curr[2]], exp_A[curr[2]]);
                    upd_exp.push(cnt);
                    cnt++;
                }
                if(curr[1]==(ll)'|') {
                    OR(exp_0[curr[0]], exp_1[curr[0]], exp_a[curr[0]], exp_A[curr[0]], exp_0[curr[2]], exp_1[curr[2]], exp_a[curr[2]], exp_A[curr[2]]);
                    upd_exp.push(cnt);
                    cnt++;
                }
                if(curr[1]==(ll)'^') {
                    XOR(exp_0[curr[0]], exp_1[curr[0]], exp_a[curr[0]], exp_A[curr[0]], exp_0[curr[2]], exp_1[curr[2]], exp_a[curr[2]], exp_A[curr[2]]);
                    upd_exp.push(cnt);
                    cnt++;
                }
            }
            // FOR(i,0,curr.size()) {
            //     cout << curr[i];
            // }
            // cout << " ---> ";
            // cout << ans_0 << " " << ans_1 << " " << ans_a << " " << ans_A << endl;
        }
        else {
            upd_exp.push((ll)exp[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string L;
        cin >> L;
        exp_0.clear();
        exp_1.clear();
        exp_a.clear();
        exp_A.clear();
        cnt = 1000;

        exp_0[(ll)'#'] = 748683265;
        exp_1[(ll)'#'] = 748683265;
        exp_a[(ll)'#'] = 748683265;
        exp_A[(ll)'#'] = 748683265;

        if(L.length()==1) {
            cout << exp_0[(ll)'#'] << " " << exp_1[(ll)'#'] << " " << exp_a[(ll)'#'] << " " << exp_A[(ll)'#'] << endl;
        }else {
            solve(L);
            cout << exp_0[cnt-1] << " " << exp_1[cnt-1] << " " << exp_a[cnt-1] << " " << exp_A[cnt-1] << endl;
        }
    }
    return 0;
}
