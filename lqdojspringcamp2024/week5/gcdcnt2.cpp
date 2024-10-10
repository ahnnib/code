#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define dbg cout << "dfad\n";

const ll mod = 1e9 + 7;
const ll N = 1e6 + 1;

int d[N], cnt[N]; ll fac[N], inv[N], dp[N];
int main() {
    int n, k, g, a; cin >> n >> k >> g;

    // cnt[i]: so a[i] la boi so cua i
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        mx = max(mx, a);
        d[a]++;
    }

    for (int i = 1; i <= mx; i++) {
        for (int j = i; j <= mx; j += i) {
            cnt[i] += d[j];
        }   
    }

    auto exp = [&](ll a, ll b) -> ll {
        ll res = 1;
        while (b) {
            if (b&1) (res *= a) %= mod;
            (a *= a) %= mod;
            b >>= 1;
        }
        return res;
    };
    fac[0] = 1; for (ll i = 1; i <= n; i++) fac[i] = fac[i-1] * i % mod;
    inv[n] = exp(fac[n], mod-2);
    for (ll i = n-1; i >= 0; i--) inv[i] = inv[i+1] * (i+1) % mod;
    auto nCr = [&](int n, int r) -> ll {
        return fac[n] * inv[r] % mod * inv[n-r] % mod;
    };

    for (int i = mx; i >= g; i--) {
        dp[i] = nCr(cnt[i], k);
        for (int j = i<<1; j <= mx; j += i) {
            (dp[i] -= dp[j]) %= mod;
        }
        (dp[i] += mod) %= mod;
    }
    cout << dp[g];
}