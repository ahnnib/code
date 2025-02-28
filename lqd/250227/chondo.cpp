#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    freopen("chondo.inp", "r", stdin);
    freopen("chondo.out", "w", stdout);
    int n, m; cin >> n >> m;

    int w[n+1] = {}, v[n+1] = {};
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

    int dp[m+1] = {};
    for (int i = 1; i <= n; i++) {
        for (int j = w[i]; j <= m; j++) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
        // choose each item only once: for j = m -> w[i]
    }

    cout << dp[m];
}