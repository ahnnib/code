#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int n, m, k;
const int N = 1e5 + 1;
vector<int> deg(N);
vector<int> group(N);
vector<bool> vis(N);
vector<int> par(N);
vector<int> sz(N);
void init() {
    for (int i = 1; i < N; i++) sz[i] = 1;
    for (int i = 1; i < N; i++) par[i] = i;
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
}

void dfs(int u) {
    vis[u] = 1;
    group[deg[id]].push_back(u);
    for (int v : G[u]) if (!vis[v]) dfs(v);
}

int main() {
    init();

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        deg[u]++;
        deg[v]++;
        G[u].push_back(v);
        G[v].push_back(u);
        unite(u, v);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    int res = 0;
    for (int dg = 1; dg < N; dg++) {
        vector<bool> mark(N);
        int cnt = 0, tmp = 0;
        for (int u : group[dg]) {
            if (cnt >= k) break;
            int v = find(u);
            if (!mark[v]) {
                tmp += sz[v];
                cnt++;
            }
            mark[v] = 1;
        }
        res = max(res, tmp);
    }

    cout << res;
}