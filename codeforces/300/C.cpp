#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

const int N = 1e6 + 1;
const ll mod = 1e9 + 7;
array<ll, N> fac, inv;

int main() {
    int a, b, n; cin >> a >> b >> n;
    auto exp = [&](ll a, ll b) -> ll {
        ll res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    };
    auto pp = [&]() -> void {
        fac[0] = 1;
        for (ll i = 1; i < N; i++) fac[i] = fac[i-1] * i % mod;
        inv[N-1] = exp(fac[N-1], mod-2);
        for (int i = N-2; i >= 0; i--) inv[i] = inv[i+1] * (i+1) % mod;
    };
    auto check = [&](ll sum, int a, int b) -> bool {
        while (sum > 0) {
            if (sum%10 != a && sum%10 != b) return 0;
            sum /= 10;
        }
        return 1;
    };
    auto nCr = [&](ll n, ll r) -> ll {
        return fac[n] * inv[r] % mod * inv[n-r] % mod;
    };

    pp();
    ll res = 0;
    for (int i = 0; i <= n; i++) {
        ll sum = a * i + b * (n-i);
        if (check(sum, a, b)) {
            res += nCr(n, i);
            res %= mod;
        }
    }
    cout << res;
}