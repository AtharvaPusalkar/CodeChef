#include <bits/stdc++.h>
#define MOD 1000000007
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define pii pair<ll, ll>
#define endl "\n"
#define FOR(a,b) for (long long i = a; i < b; i++)
#define REV(a,b) for (long long i = b; i > a; i--)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
        ll N;
        cin >> N;
        while(N--) {
            string s;
            cin >> s;
            ll cnt_0 = 0;
            ll cnt_1 = 0;
            for(ll i=0;i<s.size();i++) {
                if(s[i]=='0') {
                    cnt_0++;
                }else {
                    cnt_1++;
                }
            }
            if(cnt_0==s.size()||cnt_1==s.size()) {
                cout << 0 << endl;
            }else {
                ll res = 0;
                ll cnt_01 = 0;
                ll cnt_10 = 0;
                for(ll i=1;i<s.size()-1;i++) {
                    if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i]=='0') {
                        res++;
                    }
                }
                for(ll i=0;i<s.size()-1;i++) {
                    if(s[i]=='0'&&s[i+1]=='1') {
                        cnt_01++;
                    }else if(s[i]=='1'&&s[i+1]=='0') {
                        cnt_10++;
                    }
                }
                //cout << "cnt_01 " << cnt_01 << " cnt_10 " << cnt_10 << endl;
                //cout << "c " << res << endl;
                res += max(abs(cnt_01-res), abs(cnt_10-res));
                cout << res-1 << endl;
            }
        }
    return 0;
}
