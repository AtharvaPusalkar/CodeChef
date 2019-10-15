#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define eb emplace_back
using namespace std;

int minKey(int key[], bool mstSet[], int N){
    int min = INT_MAX, min_index;

    for (int v = 0; v < N; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

int printMST(int parent[], vector<vector<int>> graph)
{
    int ans=0;
    for (int i = 1; i < graph.size(); i++)
        ans += graph[i][parent[i]];
    return ans;
}

int primMST(vector<vector<int>> graph, int N)
{
    int parent[N];

    int key[N];

    bool mstSet[N];

    for (int i = 0; i < N; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < N - 1; count++) {
        int u = minKey(key, mstSet, N);
        mstSet[u] = true;
        for (int v = 0; v < N; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    return printMST(parent, graph);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int tc=0;tc<t;tc++){
        int M, N;
        cin >> N >> M;
        int C[M], D[M];
        vector<std::vector<int>> G(N, vector<int>(N, 2));
        for(int i=0;i<N;i++){
            G[i][i] = 0;
        }
        for(int i=0;i<M;i++){
            cin >> C[i] >> D[i];
            G[C[i]-1][D[i]-1] = 1;
            G[D[i]-1][C[i]-1] = 1;
        }
        int res = primMST(G, N);
        cout << "Case #" << tc+1 << " " << res << "\n";
    }
    return 0;
}
