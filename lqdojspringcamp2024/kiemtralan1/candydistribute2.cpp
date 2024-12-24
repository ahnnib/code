#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const ll mod = 1e9 + 7;
ll n, k, l, h;

ll exp(ll a, ll b) {
    ll res = 1;
    for (; b > 0; b >>= 1) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll nCr(ll n, ll r) {
    if (n <= 0) {
        return 0;
    }
    ll P = 1;
    for (ll i = n - r + 1; i <= n; i++) {
        P = P * i % mod;
    }
    ll Q = 1;
    for (ll i = 1; i <= r; i++) {
        Q = Q * i % mod;
    }
    return P * exp(Q, mod - 2) % mod;
}

int main() {
    cin >> n >> k >> l >> h;
    ll M = n - k * l + k - 1;
    ll res1 = nCr(M, k - 1);
    ll res2 = k * nCr(M - (h - l + 1), k - 1) % mod;
    // cout << (res1 - res2 + mod) % mod;
    cout << res1 << ' ' << res2;
}