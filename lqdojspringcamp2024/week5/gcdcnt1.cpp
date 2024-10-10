#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
const ll mod = 1e9 + 7;

int main() {
    int n, g; cin >> n >> g;
    auto f = [n](ll g) -> ll {// sl boi cua g
        return n/g;
    };
    auto exp = [](ll x) -> ll {
        ll t = 2, res = 1;
        for (; x; x >>= 1) {
            if (x & 1) (res *= t) %= mod;
            (t *= t) %= mod;
        }
        return res;
    };
    ll dp[n+1];
    for (int i = n; i >= g; i--) {
        dp[i] = exp(f(i)) - 1/*so tap con khac rong*/;
        for (int j = i<<1; j <= n; j += i)
            (dp[i] -= dp[j]) %= mod;
        (dp[i] += mod) %= mod;
    }
    cout << dp[g];
}