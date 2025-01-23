#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int n, k;
ll dp[(1<<15) + 1][16];
void sol() {
    cin >> n >> k;

    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int mask = 0; mask < 1<<n; mask++) {
        for (int q = 1; q <= n; q++) {
            if ((mask >> (q-1)) & 1) continue;

            for (int p = 0; p <= n; p++) {
                if (p != 0 && abs(q - p) > k) continue;

                dp[mask | (1 << (q - 1))][q] += dp[mask][p];
            }
        }
    }

    ll res = 0; int fullMask = (1<<n) - 1;
    for (int i = 1; i <= n; i++) {
        res += dp[fullMask][i];
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}