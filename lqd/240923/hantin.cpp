#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll ext(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = ext(b, a%b, x1, y1);
    x = y1;
    y = x1 - a/b * y1;
    return g;
}
ll mod_inv(ll a, ll m) {
    ll x, y;
    ext(a, m, x, y);
    return (x%m+m)%m;
}
int main() {
    freopen("HANTIN.INP", "r", stdin);
    freopen("HANTIN.OUT", "w", stdout);
    int n; cin >> n;
    int a[n], m[n]; for (int i = 0; i < n; i++) cin >> a[i] >> m[i];

    ll M = 1;
    for (int i = 0; i < n; i++) {
        M *= m[i];
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll aa = (a[i] + m[i]*1000000000ll)%m[i];
        ll mm = M / m[i];
        ll inv = mod_inv(mm, m[i]);
        res = (res + aa * mm % M * inv) % M;
    }
    cout << res ;
}
