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
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N;
int prime_arr[1000001];
int prime_count[1000001];
int cost[1000001];

// 10 pts

void sieve() {
    prime_arr[0] = 1;
    prime_arr[1] = 1;
    for (int i=2; i*i<=1000000; i++) {
        if (prime_arr[i] == 0) {
            for (int j=i*2; j<=1000000; j += i)
                if(prime_arr[j]==0) {
                    prime_arr[j] = i;
                }
        }
    }
    FOR(i,2,1000001) {
        if(prime_arr[i]==0) {
            prime_arr[i] = i;
        }
    }
}

void compute_div(vi path,int cost[]) {
    memset(prime_count, 0, sizeof(prime_count));
    FOR(i,0,path.size()) {
        path[i] = cost[path[i]];
        ll t = path[i];
        while(t!=1) {
            prime_count[prime_arr[t]]++;
            t = t/prime_arr[t];
        }
    }
    int m = *max_element(path.begin(), path.end());
    ll ans = 1;
    FOR(i,2,m+1) {
        ans = (ans%MOD * (prime_count[i] + 1)%MOD)%MOD;
    }
    cout << ans << endl;
}

void DFS(vi graph[], vi path, bool visited[], ll s, ll d, int cost[]) {
    path.PB(s);
    if(s==d) {
        // cout << "curr -> ";
        // ll t = 1;
        // FOR(i,0,path.size()) {
        //     t *= cost[path[i]];
        // }
        // cout << t << endl;
        compute_div(path, cost);
        return;
    }

    visited[s] = true;

    bool ok = false;
    if(!graph[s].empty()) {
        //cout << "graph size = " << graph[s].size() << endl;
        FOR(i,0,graph[s].size()) {
            if(!visited[graph[s][i]]) {
                DFS(graph, path, visited, graph[s][i], d, cost);
                ok = true;
            }
        }
    }
    if(!ok) {
        path.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    mset(prime_arr, 0);
    sieve();
    int t;
    cin >> t;
    while(t--) {
        cin >> N;
        vi graph[N+1], path;
        FOR(i,0,N-1) {
            int X,Y;
            cin >> X >> Y;
            graph[X].PB(Y);
            graph[Y].PB(X);
        }
        FOR(i,0,N) {
            cin >> cost[i+1];
        }
        int Q;
        cin >> Q;
        while(Q--) {
            int u,v;
            cin >> u >> v;
            bool visited[N+1];
            mset(visited, false);
            //cout << "boi" << endl;
            DFS(graph, path, visited, u, v, cost);
        }
    }
    return 0;
}
