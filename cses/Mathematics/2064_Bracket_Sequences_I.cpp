#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const ll mod = 1e9 + 7;

int main() {

    ll n; cin >> n;

    //catalan number
    if (n & 1) return cout << 0, 0;

    n /= 2;

    ll P = 1, Q = 1;
    for (ll i = n+2; i <= n<<1; i++) {
        (P *= i) %= mod;
        (Q *= (i - n)) %= mod;
    }

    auto exp = [&](ll a, ll b) -> ll {
        ll res = 1;
        for (; b; b >>= 1) {
            if (b & 1) (res *= a) %= mod;
            (a *= a) %= mod;
        }
        return res;
    };

    cout << P * exp(Q, mod-2) % mod;
}