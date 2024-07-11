#include <iostream>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

long long expo(long long a, long long b, long long mod) {
    if (b == 0) return 1;
    long long t = expo(a, b>>1, mod) % mod;
    return t * t % mod * (b & 1 ? a : 1) % mod;
}

void solve() {
    bool neg = 1; // 1: dãy toàn âm
    int n, k; cin >> n >> k; int a[n]; for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] >= 0) neg = 0;
    }

    int MAX_cur = 0, MAX = -1e18;
    for (int i = 0; i < n; i++) {
        MAX_cur = max(a[i], MAX_cur + a[i]);
        MAX = max(MAX, MAX_cur);
    }

    if (neg) MAX = 0;
    // cout << "debug: " << MAX << '\n';

    // \sum{a} + 2^(k-1) * MAX
    int res = 0;
    for (int i = 0; i < n; i++) {
        (res += a[i]) %= mod;
    }
    int t = ((expo(2, k, mod) - 1) * (MAX % mod)) % mod;
    // cout << t << '\n';
    res = res + t;
    res %= mod;
    // cout << res << '\n';
    res = (res + mod) % mod;

    cout << res;

    cout << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    long long NTT; cin >> NTT; while (NTT--) {
        solve();
    }
}