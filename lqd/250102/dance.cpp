#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    freopen("dance.inp", "r", stdin);
    freopen("dance.out", "w", stdout);
    int n, k; cin >> n >> k;
    int h[n+1] = {}; for (int i = 1; i <= n; i++) cin >> h[i];
    sort(h + 1, h + n + 1);
    vector< vector<ll> > dp(1001, vector<ll>(505, 1e18));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i / 2; j++) {
            ll t = h[i] - h[i-1];
            if (i > 2 && j > 0) t += dp[i-2][j-1];
            dp[i][j] = min(dp[i-1][j], t);
        }
    }
    cout << dp[n][k];
}