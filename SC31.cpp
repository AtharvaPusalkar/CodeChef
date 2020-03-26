#include <bits/stdc++.h>
#define MOD 1000000007
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define endl "\n"
#define FOR(a,b) for (long long i = a; i < b; i++)
#define REV(a,b) for (long long i = b; i > a; i--)
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<ll, ll>;
using namespace std;

template <class Q>
void scan(Q &x) {char ch = getchar(); x = 0; while (ch < '0' || ch > '9') ch = getchar(); while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();}
template <class Q>
void print(Q x) {if (x > 9) pi(x / 10); putchar(x % 10 + 48);}

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
        ll N;
        cin >> N;
        unordered_map<int, bool>mp;
        string S;
        for(ll i=0;i<N;i++) {
            cin >> S;
            for(ll j=0;j<10;j++) {
                if(S[j]=='1') {
                    mp[j] = !mp[j];
                }
            }
        }
        ll count = 0;
        for(ll i=0;i<10;i++) {
            cout << mp[i];
            if(mp[i]) {
                count++;
            }
        }
        cout << endl;
        cout << count << endl;
    }
    return 0;
}
