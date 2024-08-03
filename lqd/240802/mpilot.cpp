#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int n, a[10001][2], dp[2][10001];
int main() {
    freopen("mpilot.inp", "r", stdin);
    freopen("mpilot.out", "w", stdout);
    cin >> n; for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1];
    dp[1][1] = a[1][1];
    for (int i = 2; i <= n; i++) {
        int mn = min(i, n/2), ii = i % 2;
        dp[ii][0] = dp[1-ii][1] + a[i][0];
        dp[ii][mn] = dp[1-ii][mn-1] + a[i][1];
        for (int j = 1; j < mn; j++) {
            dp[ii][j] = min(dp[1-ii][j+1] + a[i][0], dp[1-ii][j-1] + a[i][1]);
        }
    }
    cout << dp[0][0];
}
/*
4
5 3
6 2
8 1
9 6
*/
