// chia keo euler, l <= x_i <= h
#include <bits/stdc++.h>
using namespace std;

#define ll long long
constexpr ll MOD = 1e9 + 7;

ll n, k, l, h;
vector<int> fac, ifac;

// Fast modular exponentiation
int exp(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return res;
}

// Precompute factorials and modular inverses
void precompute(ll N) {
    fac.resize(N);
    ifac.resize(N);
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
    }
    ifac[N - 1] = exp(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) {
        ifac[i] = 1LL * ifac[i + 1] * (i + 1) % MOD;
    }
}

// Modular addition utility
ll mod_add(ll a, ll b) {
    return (a + b) % MOD;
}

// Compute nCr under modulo
int nCr(ll n, ll r) {
    if (n < r || n < 0 || r < 0) return 0;
    return 1LL * fac[n] * ifac[r] % MOD * ifac[n - r] % MOD;
}

int main() {

    // Input
    cin >> n >> k >> l >> h;

    // Precompute factorials and modular inverses
    precompute(n + k);
    // Initial values
    ll M = n - k * l + k - 1;
    ll op = 1, res = 0;
    ll delta = h - l + 1;  // Precompute repeated subtraction term

    // Main computation
    for (ll k1 = 0; k1 <= k; k1++) {
        if (M < 0) break;
        res = mod_add(res, op * nCr(k, k1) % MOD * nCr(M, k - 1) % MOD);
        op = -op;
        M -= delta;
    }

    // Output result
    cout << (res + MOD) % MOD << '\n';  // Ensure result is non-negative
    return 0;
}