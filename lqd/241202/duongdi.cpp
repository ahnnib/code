#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    int m, n; cin >> m >> n;
    ll a[m+1][n+1] = {};

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    ll dp[m+1][n+1] = {};

    for (int j = 1; j <= n; j++) {
        dp[1][j] = dp[1][j-1] + a[1][j];
    }
    for (int i = 1; i <= m; i++) {
        dp[i][1] = dp[i-1][1] + a[i][1];
    }
    for (int i = 2; i <= m; i++) {
        for (int j = 2; j <= n; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + a[i][j];
        }
    }

    // for (int i = 1; i <= m; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << dp[i][j] << " \n"[j == n];
    //     }
    // }

    cout << dp[m][n];
}