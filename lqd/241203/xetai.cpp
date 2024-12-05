#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll n, W, w[1001], v[1001];
// vector< vector<ll> > dp(1001, vector<ll>(10001, -1e12));
// vector< vector<ll> > dp(2, vector<ll>(10001, -1e9));
// ll dp[2][10001];

int main() {
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    // for (int i : {0, 1}) for (int j = 0; j < 10001; j++) dp[i][j] = -100000000;
    // dp[0][0] = 0;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= W; j++) {
    //         dp[i][j] = dp[i-1][j];
    //         if (j - w[i] >= 0) {
    //             dp[i][j] = max(dp[i][j], dp[i-1][j - w[i]] + v[i]);
    //         }
    //     }
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= W; j++) {
    //         cout << dp[i][j] << " \n"[j == W];
    //     }
    // }



    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= W; j++) {
    //         dp[1][j] = dp[0][j];
    //         if (j - w[i] >= 0) {
    //             dp[1][j] = max(dp[0][j], dp[0][j - w[i]] + v[i]);
    //         }
    //     }
    //     for (int j = 0; j <= W; j++) {
    //         dp[0][j] = dp[1][j];
    //     }
    // }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= W; j++) {
    //         cout << dp[i][j] << " \n"[j == W];
    //     }
    // }



    vector<ll> dp(W + 1, -1e12);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }


    ll res = 0;
    // for (int i = 0; i <= W; i++) res = max(res, dp[n][i]);
    // for (int i = 0; i <= W; i++) res = max(res, dp[1][i]);
    for (int i = 0; i <= W; i++) res = max(res, dp[i]);
    cout << res;
}