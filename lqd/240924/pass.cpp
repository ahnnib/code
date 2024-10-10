#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define dbg cout << "dfad\n";

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll rnd(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
ll exp(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll check(ll n, ll a, ll d, ll s) {
    ll x = exp(a, d, n);
    if (x == 1 || x == n-1) return false;
    for (int r = 1; r < s; r++) {
        x = x * x % n;
        if (x == n-1) return false;
    }
    return true;
}
bool prime(ll n) {
    if (n < 4) return n == 2 || n == 3;
    if (n%2 == 0 || n%3 == 0) return 0;
    ll s = 0, d = n-1;
    while (!(d & 1)) d >>= 1, s++;
    for (int i = 0; i < 5; i++) {
        ll a = rnd(2, n-2);
        if (check(n, a, d, s)) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("PASS.INP", "r", stdin);
    freopen("PASS.OUT", "w", stdout);

    int n; cin >> n;
    ll a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        cout << prime(a) << '\n';
    }
}
