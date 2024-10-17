#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const int N = 1e5 + 1;
ll n, m;
ll w[N], d[N];
ll dp[4000][12805];

int main() {
    freopen("charm.inp", "r", stdin);
    freopen("charm.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> d[i];
    }

	for (int i = 1; i <= n; i++) {
		for (int s = 0; s <= m; s++) {
			dp[i][s] = dp[i - 1][s];
			if (s >= w[i])
                dp[i][s] = max(dp[i][s], dp[i - 1][s - w[i]] + d[i]);
		}
	}

    ll res = -1e18;
    for (int i = 0; i <= m; i++) {
        res = max(res, dp[n][i]);
    }

    cout << res;
}