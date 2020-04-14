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

// 0.87 pts in DIV 1

vi min_ind(int row[], int n) {
    vi indices;
    int m = *min_element(row, row+n);
    FOR(i,0,n) {
        if(row[i]==m) {
            indices.PB(i);
        }
    }
    return indices;
}

int choice(int row[], int n, vi indices) {
    vi arr;
    FOR(i,0,indices.size()) {
        arr.PB(row[indices[i]]);
    }
    sort(arr.begin(), arr.end());
    int cnt = 1;
    int val = arr[0];
    int curr = 1;
    FOR(i,1,arr.size()) {
        if(arr[i]==arr[i-1]) {
            curr++;
        }else {
            if(curr>cnt) {
                cnt = curr;
                val = arr[i-1];
            }
            curr = 1;
        }
    }
    if(curr > cnt) {
        val = arr[arr.size()-1];
    }
    return val;
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int N,M,K;
        cin >> N >> M >> K;
        int c[N][K];
        FOR(i,0,N) {
            FOR(j,0,K) {
                cin >> c[i][j];
            }
        }
        vi answers;

        int cost[K];
        mset(cost,0);
        vi indices = min_ind(c[0], K);
        answers[0] = choice(c[0], K, indices);
        indices.clear();

        FOR(i,1,N) {
            //cout << "boi" << endl;
            indices = min_ind(c[i], K);
            answers[i] = choice(c[i], K, indices);
            FOR(j,0,K) {
                if(c[i][j]==answers[i]) {
                    cost[j]++;
                }
            }
            indices.clear();
        }

    }
    return 0;
}
