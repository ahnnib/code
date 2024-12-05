#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const int C = 25500;
ll dp[26][500000] = {};

int main() {
    int n, m; cin >> n >> m;
    int a[n+1] = {};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[0][C] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = -C; j <= C; j++) {
            dp[i][j + C] = dp[i-1][j + C];
            if (j + C > a[i]) dp[i][j + C] += dp[i - 1][j - a[i] + C];
        }
    }

    cout << dp[n][m + C] - !m; // truong hop m = 0
}