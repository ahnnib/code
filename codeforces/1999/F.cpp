#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

const int N = 2e5 + 1;
const ll mod = 1e9 + 7;
ll fac[N], ifac[N];

ll exp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void pp() {
    fac[0] = 1; for (ll i = 1; i < N; i++) fac[i] = fac[i-1] * i % mod;
    ifac[N-1] = exp(fac[N-1], mod-2);
    for (ll i = N-2; i >= 0; i--) ifac[i] = ifac[i+1] * (i+1) % mod;
}
ll nCr(int n, int k) {
    if (n < k) return 0;
    return fac[n] * ifac[k] % mod * ifac[n-k] % mod;
}
void solve() {
    ll n, k; cin >> n >> k;
    ll x = 0; for (int i = 0; i < n; i++) { bool a; cin >> a; x += a; }
    ll res = 0;
    for (int i = k / 2 + 1; i <= min(x, k); i++) {
        res += nCr(x, i) * nCr(n-x, k-i) % mod;
        res %= mod;
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pp();
    int t = 1;
    cin >> t;
    while(t--) solve();
}