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
        if((step-1)%cnt==0&&step!=1) {
            step = 1;
            day++;
        }
        if(!done[books[ind]]) {
//            cout << "day " << day << " step " << step << " book " << books[ind] << endl;
            batch.PB(books[ind]);
            step++;
            done[books[ind]] = true;
        }
        ind++;
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
    return ((a_sum/mp_m[a])/mp_t[a])*lib[a].size() < ((b_sum/mp_m[b])/mp_t[b])*lib[b].size();
}

int main() {
    freopen("f_libraries_of_the_world.txt", "r", stdin);
    freopen("f_output.txt", "w", stdout);
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
    ll cost = 0;
    vi consider;
    ll ind=0;
    while(cost<D&&ind!=L) {
        if(cost+mp_t[ind]>D) {
            break;
        }else {
            consider.PB(indices[ind]);
            cost += mp_t[ind];
            ind++;
        }
    }

    ind = 0;
    day = mp_t[consider[0]];
    vi order;
    unordered_map<ll,vi>order_scans;
    unordered_map<ll,ll>nos;
    while(day<D&&ind<consider.size()) {
        vi ret = solve(lib[consider[ind]], day,D,mp_m[consider[ind]]);
        nos[consider[ind]] = ret.size();
        if(ret.size()) {
            order.PB(consider[ind]);
            order_scans[consider[ind]] = ret;
        }
        ind++;
    }
    cout << order.size() << endl;
    FOR(i,0,order.size()) {
        cout << order[i] << " " << nos[order[i]] << endl;
        FOR(j,0,order_scans[order[i]].size()) {
            cout << order_scans[order[i]][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
