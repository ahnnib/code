#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int n, a[501];
ll dp[501][501];
ll f(int l, int r) {
    if (l > r || l < 0 || r > n) return 0;

    if (dp[l][r] != 0) return dp[l][r];

    for (int i = l+1; i <= r-1; i++) {
        ll x = 1ll * a[i] * a[l] * a[r] + f(l, i) + f(i, r);
        if (dp[l][r] == 0) {
            dp[l][r] = x;
            continue;
        }
        dp[l][r] = min(dp[l][r], x);
    }

    return dp[l][r];
}
int main() {
    // freopen("matrixmul.inp", "r", stdin);
    // freopen("matrixmul.out", "w", stdout);
    int n; cin >> n;
    for (int i = 0; i <= n; i++) cin >> a[i];
    // cout << f(0, n);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}