#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    freopen("invest.inp", "r", stdin);
    freopen("invest.out", "w", stdout);
    int m, n; cin >> m >> n;
    int a[m+1][n+1] = {};
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    vector< vector<ll> > dp (m+1, vector<ll>(n+1, 0));

    for (int j = 1; j <= n; j++) {
        for (int i = 0; i <= m; i++) {
            for (int x = 0; x <= i; x++) {
                dp[i][j] = max(dp[i][j], dp[i - x][j - 1] + a[x][j]);
            }
        }
    }
    cout << dp[m][n];
}