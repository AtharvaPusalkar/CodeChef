#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 2e9
#define EPS 1e-9
#define MAX LLONG_MAX
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
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

class Graph{
    ll V;
    unordered_map<ll,vector<ll>>adj;
public:
    Graph(ll V);
    void addEdge(ll v, ll w);
    bool isValid(ll s, ll d);
    ll BFS(ll src, ll dest);
};

Graph::Graph(ll V){
    this->V = V;
    unordered_map<ll,vector<ll>>adj;
}

void Graph::addEdge(ll v, ll w){
    adj[v].push_back(w);
}

bool Graph::isValid(ll s, ll d){
    bool *visited = new bool[V];
    for (ll i = 0; i < V; i++)
        visited[i] = false;

    queue<ll> q;

    visited[s] = true;
    q.push(s);

    list<ll>::iterator i;

    while (!q.empty()) {

        s = q.front();
        q.pop();

        for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {

            if (*i == d)
                return true;

            if (!visited[*i]){
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
    return false;
}

ll Graph::BFS(ll src, ll dest) {
    bool *visited = new bool[V];
    for (ll i = 0; i < V; i++)
        visited[i] = false;

    queue<ll> q;

    visited[src] = true;
    q.push(src);

    list<ll>::iterator i;
    ll dist[V];
    FOR(i,0,V) {
        dist[i] = -1;
    }
    dist[src] = 0;

    while (!q.empty()) {
        src = q.front();
        q.pop();

        for (auto i = adj[src].begin(); i != adj[src].end();i++) {

            if (!visited[*i]){
                visited[*i] = true;
                q.push(*i);
                (dist[*i]==-1)?dist[*i]=dist[src]+1:dist[*i]=min(dist[*i],dist[src]+1);
            }
        }
    }
    return dist[dest];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll K, N;
        cin >> N >> K;
        vector<string>S;
        ll last = 0;
        Graph g(4);
        FOR(i,0,N) {
            string s;
            cin >> s;
            FOR(j,0,N) {
                if(j!=i&&s[j]=='1'&&abs(i-j)<=K) {
                    g.addEdge(i, j);
                }
            }
        }
        if(g.isValid(0, N-1)) {
            cout << g.BFS(0, N-1) << endl;
        }else {
            cout << -1 << endl;
        }

    }
    return 0;
}
