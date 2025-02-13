#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const ll mod = 1e9 + 7;

int main() {
    int n; cin >> n;
    bool ok[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ok[i][j];
        }
    }

    ll dp[1<<n] = {}; // dp[mask]: number of ways to assign men with set of women represented by mask
    dp[0] = 1;
    for (int mask = 0; mask < 1<<n; mask++) {
        int cnt_men = __builtin_popcount(mask);
        for (int j = 0; j < n; j++) {
            if (!(mask & (1<<j)) && ok[cnt_men][j]) {
                int newMask = mask | (1<<j);
                dp[newMask] += dp[mask];
                dp[newMask] %= mod;
            }
        }
    }

    cout << dp[(1<<n) - 1];
}