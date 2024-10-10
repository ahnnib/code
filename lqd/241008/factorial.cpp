#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll n, p, r;

ll exp(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b & 1) (res *= a) %= m;
        (a *= a) %= m;
        b >>= 1;
    }
    return res;
}
void sub2() {
    if (n < p) {
        cout << "-1 -1\n";
        return;
    }
    if (n == 2) {
        cout << "-1 -1\n";
        return;
    }
    if (p == 2) {
        cout << "3 1\n";
    }
    else {
        cout << "2 1\n";
    }
}
void sub13() {
    if (n >= 2 * p) {
        cout << "-1 -1\n";
        return;
    }
    if (p <= n && n < 2 * p) {
        cout << p << ' '; // p = k
        ll t = 1;
        for (ll i = 2; i <= n; i++) {
            if (i != p) (t *= i) %= p;
        }
        t = exp(t, p-2, p);
        t = t * (r%p) % p;
        cout << t;
        return;
    }
    else {
        ll t = 1;
        for (ll i = 2; i <= n; i++) (t *= i) %= p;
        t = exp(t, p-2, p);
        for (ll k = 2; k <= n; k++) {
            ll v = (r%p) * (k%p) * t%p;
            if (v < k) {
                cout << k << ' ' << v;
                return;
            }
        }
        cout << "-1 -1\n";
    }
}

int main() {
    freopen("factorial.inp", "r", stdin);
    freopen("factorial.out", "w", stdout);

    cin >> n >> p >> r;
    if (r == 0) sub2();
    else sub13();
}