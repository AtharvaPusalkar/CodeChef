#include <bits/stdc++.h>
#define MOD 1000000007
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define FOR(a,b) for (long long i = a; i < b; i++)
#define REV(a,b) for (long long i = b; i > a; i--)
typedef long long ll;
typedef unsigned long long ull;
#define pair<ll, ll> pii
using namespace std;

int gcd(ll a, ll b) {
    if (a == 0)
       return b;
    if (b == 0)
       return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int largest(ll arr[], ll n) {
    return *max_element(arr, arr+n);
}

 ll lcm(ll a, ll b) {
    return (a*b)/gcd(a, b);
 }

ll power(ll x, ull y) {
    ll temp;
    if(y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
    {
        if(y > 0)
            return x * temp * temp;
        else
            return (temp * temp) / x;
    }
}

bool comp(int a, int b) {
    return (a < b);
}

bool isPrime(ll n) {

    if (n == 1) {
        return false;
    }

    ll i = 2;

    while (i*i <= n) {

        if (n % i == 0) {
             return false;
        }
        i += 1;
    }
    return true;
}

int gcdofarray(vector<ll>v, ll n) {
    ll result = v[0];
    for (ll i = 1; i < n; i++)
        result = gcd(v[i], result);
    return result;
}

bool powertwo(ll x) {
  return x&& (!(x&(x-1)));
}

ll fast_mod(const ll input, const ll ceil) {
    return input >= ceil ? input % ceil : input;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        unordered_map<int, int>pos;
        unordered_map<int, int>cnt;
        vector<int>arr;
        arr.PB(0);
        pos[0] = 1;
        cnt[0] = 1;
        for(int i=2;i<=N;i++) {
            if(cnt[arr[arr.size()-1]]!=1) {
                ll curr = arr.size() - pos[arr[arr.size()-1]];
                pos[arr[arr.size()-1]] = arr.size();
                cnt[curr]++;
                if(cnt[curr]==1) {
                    pos[curr] = i;
                }
                arr.PB(curr);
            }
            else{
                ll curr = 0;
                if(arr[arr.size()-1]==curr) {
                    pos[0] = arr.size();
                }
                arr.PB(0);
                cnt[0]++;
            }
        }
        cout << cnt[arr[arr.size()-1]] << endl;
    }
    return 0;
}
