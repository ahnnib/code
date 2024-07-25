#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define debug cout << "dfad\n";

const int N = 1e5 + 7;
vector<int> dp(1000007);
signed main() {
    freopen("tower.inp", "r", stdin);
    freopen("tower.out", "w", stdout);
    int n; cin >> n;
    int r[n+1] = {}, h[n+1] = {}; for (int i = 1; i <= n; i++) cin >> r[i] >> h[i];
    int res = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, r[i]);
        for (int j = r[i]; j <= mx; j++) dp[r[i]] = max(dp[r[i]], dp[j] + h[i]);
    }
    cout << *max_element(dp.begin(), dp.end());
}