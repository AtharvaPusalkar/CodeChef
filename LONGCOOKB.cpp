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
#define REV(i,a,b) for (long long i = a; i > b; i--)
#define mset(a, v) memset(a, v, sizeof(a))
typedef std::pair<int, int> pii;
typedef std::vector<long long> vi;
typedef std::vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

string days[] = {
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday",
    "Monday",
    "Tuesday"
  };
//ll closest[] = {5,4,3,2,1,0,6};
ll closest[] = {2,1,0,6,5,4,3};
ll closest_sunday[] = {4,3,2,1,0,1,2};
ll months[] = {31,28,31,30,31,30,31,31,30,31,30,31};

bool is_leap(ll y) {
    return (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));
}

ull count_days(ull y, ull m, ull d) {
  m = (m + 9) % 12;
  y -= m / 10;
  ull dn = 365*y + y/4 - y/100 + y/400 + (m*306 + 5)/10 + (d - 1);
  return dn%7;
}

ll solve(ll Y, ll M) {
    ll first_day = count_days(Y,M,1);
    ll first_fri = 1+closest[first_day];
    ll upper = months[M-1];
    ll res=0;
    if(is_leap(Y)&&M==2) {
        upper = 29;
    }
    ll sunday = 1+closest_sunday[first_day];
    ll penul_sunday;
    ll cnt = 1;
    while(sunday<upper) {
        if((sunday+7)<=upper) {
            sunday += 7;
            cnt++;
        }else {
            break;
        }
    }
    penul_sunday = sunday - 7;
    if((penul_sunday>=first_fri)&&(penul_sunday<first_fri+10)) {
        res++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        //cout << "test case #" << t << endl;
        ll M1, M2, Y1, Y2;
        cin >> M1 >> Y1 >> M2 >> Y2;
        //cout << is_leap(2020) << endl;
        // cout << "First Friday for " << M1 << " " << Y1 << " falls on " << 1+closest[count_days(Y1, M1, 1)] << endl;
        ll curr_year = Y1;
        ll curr_month = M1;
        bool flag = true;
        ll res = 0;
        if(Y1==Y2) {
            FOR(i,M1,M2+1) {
                ll ret = 0;
                ret = solve(Y1,i);
                //if(ret) cout <<i << " " << Y1 << endl;
                res += ret;
            }
        }else {
            while(flag&&Y1<=Y2) {
                if(Y1==Y2) {
                    FOR(i,M1,M2+1) {
                        ll ret = 0;
                        ret = solve(Y1,i);
                        //if(ret) cout <<i << " " << Y1 << endl;
                        res += ret;
                    }
                }else {
                    FOR(i,M1,13) {
                        ll ret = 0;
                        ret = solve(Y1,i);
                        //if(ret) cout <<i << " " << Y1 << endl;
                        res += ret;
                    }
                    M1 = 1;
                }
                Y1++;
            }
        }
        cout << res << endl;
    }
    return 0;
}
