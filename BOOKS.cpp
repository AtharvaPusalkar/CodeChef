#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 2e9
#define EPS 1e-9
#define MAX LLONG_MAX
#define MIN LLONG_MIN
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

ll B,L,D;
vi indices;
vvi lib;
unordered_map<ll,ll>mp_n;
unordered_map<ll,ll>mp_t;
unordered_map<ll,ll>mp_m;
unordered_map<ll,bool>done;
ll day;
vi S;

vi solve(vi books, ll start, ll up, ll cnt) {
    ll ind = 0;
    vi batch;
    ll step = 1;
    day = start;
    while(ind!=books.size()&&day!=up) {
        if((step-1)%cnt==0) {
            step = 1;
            day++;
        }
        cout << "day " << day << " step " << step << " book " << books[ind] << endl;
        if(!done[books[ind]]) {
            batch.PB(books[ind]);
            ind++;
            step++;
        }
    }
    return batch;
}

bool comp(ll a, ll b) {
    ll a_sum=0, b_sum=0;
    FOR(i,0,lib[a].size()) {
        if(!done[lib[a][i]]) {
            a_sum += lib[a][i];
        }
    }
    FOR(i,0,lib[b].size()) {
        if(!done[lib[b][i]]) {
            b_sum += lib[b][i];
        }
    }
    return a_sum < b_sum;
}

int main() {
    freopen("a_example.txt", "r", stdin);
    freopen("a_output.txt", "w", stdout);
    cin >> B >> L >> D;
    FOR(i,0,B) {
        ll e;
        cin >> e;
        S.PB(e);
    }
    FOR(i,0,L) {
        cin >> mp_n[i] >> mp_t[i] >> mp_m[i];
        vi b;
        lib.PB(b);
        FOR(j,0,mp_n[i]) {
            ll e;
            cin >> e;
            lib[i].PB(e);
        }
        indices.PB(i);
    }
    sort(indices.rbegin(),indices.rend(),comp);
    vi res_arr;
    unordered_map<ll,ll>nos;
    ll ind = 0;
    day = 0;
    vi order;
    while(day<D&&ind!=L) {
        day += mp_t[ind];
        vi ret = solve(lib[indices[ind]],day,D,mp_m[ind]);
        nos[ind]  = ret.size();
        if(ret.size()) {
            order.PB(ind);
        }
        ind++;
        FOR(i,0,ret.size()) {
            res_arr.PB(ret[i]);
        }
    }
    cout << ind-1 << endl;
    ind = 0;
    FOR(i,0,order.size()) {
        cout << order[i] << " " << nos[order[i]] << endl;
        FOR(j,ind,ind+nos[order[i]]) {
            cout << res_arr[j] << " ";
        }
        cout << endl;
        i += nos[order[i]];
    }
    cout << endl;
    return 0;
}
