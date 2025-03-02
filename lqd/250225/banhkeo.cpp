/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int n, m, k;
int p[501];

vector<pair<int, int> > G[1001];
vector<bool> vis(1001);
void dfs(int u) {
    vis[u] = 1;
    for (pair<int, int> v : G[u]) if (!vis[v.first]) dfs(v.first);
}

int main() {
    freopen("banhkeo.inp", "r", stdin);
    freopen("banhkeo.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        cin >> p[i];
    }
    sort(p + 1, p + 1 + k);

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        if (p[1] <= w) {
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt;
}
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int n, m, k;
int p[501];

vector<int> par(1001);
vector<int> sz(1001);
void init() {
    iota(par.begin(), par.end(), 0);
    fill(sz.begin(), sz.end(), 1);
}
int find(int u) {
    return u == par[u] ? u : par[u] = find(par[u]);
}
void unite(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
    sz[v] = 0;
}


int main() {
    freopen("banhkeo.inp", "r", stdin);
    freopen("banhkeo.out", "w", stdout);
    init();
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        cin >> p[i];
    }
    sort(p + 1, p + 1 + k);

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        if (p[1] <= w) {
            unite(u, v);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += sz[i] > 0;
    }
    cout << cnt;
}