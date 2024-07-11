#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    #ifndef ONLINE_JUDGE
    #else
    freopen("trader.inp", "r", stdin);
    freopen("trader.out", "w", stdout);
    #endif

    ll n, a, x, b, y; cin >> n >> a >> x >> b >> y;
    ll P[n+1] = {}; for (int i = 1; i <= n; i++) cin >> P[i];

    ll dp[n+1] = {}; for (int i = 1; i <= n; i++) dp[i] = -1e18;
    dp[a] = P[a] - x; dp[b] = P[b] - y;
    for (int i = 1; i <= n; i++) {
        if (i - a >= 0) dp[i] = max(dp[i], dp[i - a] + P[i] - x);
        if (i - b >= 0) dp[i] = max(dp[i], dp[i - b] + P[i] - y);
    }
//    for (int i = 0; i <= n; i++) cout << dp[i] << ' ';
    cout << dp[n];
}
