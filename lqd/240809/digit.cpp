#include <iostream>
#include <cstdio>
using namespace std;
#define ll unsigned long long
#define debug cout << "dfad\n";

ll a, b, k;

ll mul(ll x, ll y, ll mod) {
    ll res = 0;
    while (y > 0) {
        if (y & 1) res = (res + x) % mod;
        x = (x + x) % mod;
        y >>= 1;
    }
    return res;
}
ll exp(ll x, ll y, ll mod) {
    ll res = 1;
    while (y) {
        if (y & 1) res = mul(res, x, mod);
        x = mul(x, x, mod);
        y >>= 1;
    }
    return res;
}

int main() {
    freopen("digit.inp", "r", stdin);
    freopen("digit.out", "w", stdout);
    cin >> a >> b >> k;
    a %= b;
    ll t = mul(a, exp(10, k-1, b), b);
    cout << t * 10 / b << '\n';
}