#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int main() {
    int n, w; cin >> n >> w;
    int a[n+1], b[n+1]; for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    int dp[n+1][w+1] = {};
    for (int i = 0; i <= n; i++) for (int j = 0; j <= w; j++) dp[i][j] = -1e9;
    for (int i = 1; i <= n; i++) {
        for (int j = w; j <= w; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j - a[i]] + b[i]);
        }
    }
    cout << dp[n][w];
}