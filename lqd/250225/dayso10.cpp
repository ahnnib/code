#include <bits/stdc++.h>
#define task "DAYSO10"
#define int long long
using namespace std;

const int N = 3e3;

int dp[N+5][N+5], a[N+5];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

	int n, ans = 0; cin >> n;

	for (int x = 1; x <= n; x++) cin >> a[x];

	for (int l = n; l >= 1; l--) {
		for (int r = l+2; r <= n; r++) {
			dp[l][r] = max(0LL, dp[l+1][r-1])+a[l]*a[r];
		}
	}

	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			ans = max(ans, dp[l][r]);
		}
	}

	return cout << ans << "\n", 0;
}