#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    int n; ll c; cin >> n >> c;
    ll h[n+1] = {};
    for (int i = 1; i <= n; i++) cin >> h[i];

    vector< vector<ll> > dp(n + 1, vector<ll>(1001, 1e18));

    for (int k = 1; k <= 1000; k++) {
        dp[1][k] = 1ll * (k - h[1]) * (k - h[1]);
    }

    for (int i = 2; i <= n; i++) {
        for (int k = 1; k <= 1000; k++) {
            for (int prev_k = 1; prev_k <= 1000; prev_k++) {
                ll t1 = c * abs(k - prev_k);
                ll t2 = (k - h[i]) * (k - h[i]);
                dp[i][k] = min(dp[i][k], dp[i-1][prev_k] + t1 + t2);
            }
        }
    }

    ll res = 0;
    for (int k = 1; k <= 1000; k++) res = max(res, dp[n][k]);
    cout << res;
}