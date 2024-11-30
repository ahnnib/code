#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const ll mod = 1e9 + 7;
ll a, b, n, x;

ll exp(ll a, ll b) {
    ll res = 1;
    for (; b; b >>= 1) {
        if (b & 1) (res *= a) %= mod;
        (a *= a) %= mod;
    }
    return res;
}

int main() {
    freopen("hamso.inp", "r", stdin);
    freopen("hamso.out", "w", stdout);

    cin >> a >> b >> n >> x;

    ll res = exp(a, n) * x % mod;

    ll P = (exp(a, n) - 1 + mod) % mod;
    ll Q = exp(a-1, mod-2);
    ll res2 = P * Q % mod;

    if (a == 1) res2 = n % mod;

    res = (res + b * res2 % mod) % mod;

    cout << res;
}