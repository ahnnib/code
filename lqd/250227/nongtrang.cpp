#include <bits/stdc++.h>
#define task "NONGTRANG"
#define int long long
using namespace std;

const int N = 1e6;

bool check[N+5];

int a[N+5], dsu[N+5], n, m;

int calc(int x, int y) {
	return (x-1)*m+y;
}

int root(int v) {
	return dsu[v] < 0 ? v : dsu[v] = root(dsu[v]);
}

void unite(int u, int v) {
	if ((u = root(u)) == (v = root(v))) return;

	if (dsu[u] > dsu[v]) swap(u, v);

	dsu[u] += dsu[v], check[u] |= check[v], dsu[v] = u;

	return;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

	int sz; cin >> n >> m; sz = n*m;

	for (int x = 1; x <= sz; x++) {
		cin >> a[x]; dsu[x] = -1;
	}

	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			int cur = calc(x, y);

			for (auto dx : {-1, 0, 1}) {
				for (auto dy : {-1, 0, 1}) {
					if (abs(dx)+abs(dy) == 0) continue;

					if (x+dx < 1 || x+dx > n) continue;
					if (y+dy < 1 || y+dy > m) continue;

					int tmp = calc(x+dx, y+dy);

					if (a[cur] < a[tmp]) {
						check[cur] = 1;
					}
				}
			}
		}
	}

	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			int cur = calc(x, y);

			for (auto dx : {-1, 0, 1}) {
				for (auto dy : {-1, 0, 1}) {
					if (abs(dx)+abs(dy) == 0) continue;

					if (x+dx < 1 || x+dx > n) continue;
					if (y+dy < 1 || y+dy > m) continue;

					int tmp = calc(x+dx, y+dy);

					if (a[cur] == a[tmp]) {
						unite(cur, tmp);
					}
				}
			}
		}
	}

	int ans = 0;

	for (int x = 1; x <= sz; x++) {
		if (dsu[x] < 0 && !check[x]) ans++;
	}

	return cout << ans << "\n", 0;
}