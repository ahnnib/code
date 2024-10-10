#include <bits/stdc++.h>
using ll = int64_t;
using namespace std;
#define dbg cout << "dfad\n";

ll n, a[701];
ll dp[701][701];

ll f(int l, int r) {
    if (dp[l][r] != 0) return dp[l][r];
    if (l >= r) return 0;
    if (l+1 == r) return dp[l][r] = 0;
    for (int i = l+1; i <= r-1; i++) {
        dp[l][r] = max(dp[l][r], f(l, i) + f(i, r) + a[i] * (a[l] + a[r]));
    }
    return dp[l][r];
}

int main() {
    freopen("GAME.INP", "r", stdin);
    freopen("GAME.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    cout << f(1, n);
}
