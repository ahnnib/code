#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int main() {
    freopen("qbstr.inp", "r", stdin);
    freopen("qbstr.out", "w", stdout);
    string x, y; cin >> x >> y;
    int nx = x.size(), ny = y.size();
    x = ' ' + x; y = ' ' + y;
    int dp[nx+1][ny+1] = {};
    for (int i = 1; i <= nx; i++) {
        for (int j = 1; j <= ny; j++) {
            if (x[i] == y[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[nx][ny];
}