#include <iostream>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int m, n;
char grid[1001][1001];
bool vis[1001][1001];

bool kt(char c) {
    return c == 'x' || c == 'o' || c == '*';
}
void dfs(int u, int v, int &trau, int &ho) {
    vis[u][v] = 1;
    if (grid[u][v] == 'x') trau++;
    if (grid[u][v] == 'o') ho++;
    if (u-1 > 0 && !vis[u-1][v] && kt(grid[u-1][v])) dfs(u-1, v, trau, ho);
    if (u+1 <= m && !vis[u+1][v] && kt(grid[u+1][v])) dfs(u+1, v, trau, ho);
    if (v-1 > 0 && !vis[u][v-1] && kt(grid[u][v-1])) dfs(u, v-1, trau, ho);
    if (v+1 <= n && !vis[u][v+1] && kt(grid[u][v+1])) dfs(u, v+1, trau, ho);
}

int main() {
    freopen("trauvaho.inp", "r", stdin);
    freopen("trauvaho.out", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    int res_trau = 0, res_ho = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (!vis[i][j] && (kt(grid[i][j]))) {
                int trau = 0, ho = 0;
                dfs(i, j, trau, ho);
                if (trau >= 2 * ho) res_trau += trau;
                else res_ho += ho;
            }
        }
    }
    cout << res_trau << ' ' << res_ho;
}
/*
#include <bits/stdc++.h>
#define task "TRAUVAHO"
#define int long long
using namespace std;

const int N = 1e6;

char a[N+5];

int dsu[N+5], cnt[2][N+5], n, m;

int calc(int x, int y) {
	return (x-1)*m+y;
}

int root(int v) {
	return dsu[v] < 0 ? v : dsu[v] = root(dsu[v]);
}

void unite(int u, int v) {
	if ((u = root(u)) == (v = root(v))) return;

	if (dsu[u] > dsu[v]) swap(u, v);

	cnt[0][u] += cnt[0][v], cnt[0][v] = 0;
	cnt[1][u] += cnt[1][v], cnt[1][v] = 0;

	dsu[u] += dsu[v], dsu[v] = u;

	return;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

	cin >> n >> m;

	fill(dsu+1, dsu+n*m+1, -1);

	for (int x = 1; x <= n*m; x++) {
		cin >> a[x];

		cnt[0][x] += (a[x] == 'x');
		cnt[1][x] += (a[x] == 'o');
	}

	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			int u = calc(x, y);

			if (a[u] == '.') continue;

			if (x > 1) {
				int v = calc(x-1, y);

				if (a[v] != '.') unite(u, v);
			}
			if (y > 1) {
				int v = calc(x, y-1);

				if (a[v] != '.') unite(u, v);
			}
		}
	}

	int u = 0, v = 0;

	for (int x = 1; x <= n*m; x++) {
		if (dsu[x] >= 0) continue;

		if (cnt[1][x]*2 <= cnt[0][x]) {
			u += cnt[0][x];
		}
		else {
			v += cnt[1][x];
		}
	}

	return cout << u << " " << v << "\n", 0;
}
*/