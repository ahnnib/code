#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";
int k, n, a[101][101], dp[101][101];
int main() {
    freopen("flower.inp", "r", stdin);
    freopen("flower.out", "w", stdout);
    cin >> k >> n; for (int i = 1; i <= k; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
    // dp[i][j]: gia tri lon nhat xet den hoa thu i cam vao lo j
    for (int i = 1; i <= k; i++) for (int j = i; j <= n; j++) dp[i][j] = -2e9;
    for (int i = 1; i <= k; i++) {
        for (int j = i; j <= n; j++) {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] + a[i][j]);
        }
    }
    cout << dp[k][n];
    // for (int i = 1; i <= k; i++) for (int j = 1; j <= n; j++) cout << dp[i][j] << " \n"[j == n];
}
/*
3 5
7 23 -5 -24 16
5 21 -4 10 23
-21 5 -4 -20 20
4 6
1 1 6 4 3 10
9 1 4 7 2 7
7 2 6 10 2 3
6 10 7 1 3 9
*/