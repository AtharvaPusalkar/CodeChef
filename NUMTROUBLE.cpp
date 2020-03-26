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

bool cmp(string str1, string str2) { 
    ll n1 = str1.length(), n2 = str2.length(); 
    if (n1 < n2) 
       return true; 
    if (n2 < n1) 
       return false;

    FOR(i,0,n1) {
       if (str1[i] < str2[i]) 
          return true; 
       if (str1[i] > str2[i]) 
          return false; 
    } 
  
    return false; 
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    string A[N];
    FOR(i,0,N) {
        cin >> A[i];
    }
    sort(A,A+N,cmp);
    FOR(i,0,N) {
        cout << A[i] << endl;
    }
    return 0;
}