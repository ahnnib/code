#include <bits/stdc++.h>
#define task "DC"
#define int long long
using namespace std;

const int N = 1e5;

int a[N+5], b[N+5], lf[N+5], rt[N+5];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

	int n, m, p, T, B; cin >> n >> m >> p >> T >> B;

	for (int x = 2; x <= m+1; x++) cin >> a[x];

	for (int x = 2; x <= p+1; x++) cin >> b[x];

	a[1] = 1, a[m+2] = n, b[1] = 1, b[p+2] = n;

	for (int x = 1; x <= m+2; x++) {
		int l, r, pos;

		lf[x] = rt[x] = -1;

		l = 1, r = p+2, pos = -1;

		while (l <= r) {
			int mid = (l+r)/2;

			if (b[mid] <= a[x]) {
				l = (pos = mid)+1;
			}
			else {
				r = mid-1;
			}
		}

		if (pos != -1) lf[x] = b[pos];

		l = 1, r = p+2, pos = -1;

		while (l <= r) {
			int mid = (l+r)/2;

			if (a[x] <= b[mid]) {
				r = (pos = mid)-1;
			}
			else {
				l = mid+1;
			}
		}

		if (pos != -1) rt[x] = b[pos];
	}

	int ans = 0;

	for (int x = 2; x <= m+2; x++) {
		int res = (a[x]-a[x-1])*T;

		if (lf[x-1] != -1 && lf[x] != -1) {
			res = min(res, (a[x-1]-lf[x-1]+a[x]-lf[x])*T+B);
		}
		if (lf[x-1] != -1 && rt[x] != -1) {
			res = min(res, (a[x-1]-lf[x-1]+rt[x]-a[x])*T+B);
		}
		if (rt[x-1] != -1 && lf[x] != -1) {
			res = min(res, (rt[x-1]-a[x-1]+a[x]-lf[x])*T+B);
		}
		if (rt[x-1] != -1 && rt[x] != -1) {
			res = min(res, (rt[x-1]-a[x-1]+rt[x]-a[x])*T+B);
		}

		ans += res;
	}

	return cout << ans << "\n", 0;
}