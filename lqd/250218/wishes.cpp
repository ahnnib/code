#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const int N = 1e5 + 1;
vector<int> G[N];
vector<bool> vis(N, false);
vector<bool> source(N, true);

vector<int> par(N);
vector<int> sz(N);
void init() {
    for (int i = 1; i < N; i++) par[i] = i;
    for (int i = 1; i < N; i++) sz[i] = 1;
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
    sz[v] = -1; // avoid double-counting components
}

int n, m;

void dfs(int u) {
    vis[u] = true;
    for (int v : G[u]) {
        if (!vis[v]) dfs(v);
    }
}

int main() {
    freopen("wishes.inp", "r", stdin);
    freopen("wishes.out", "w", stdout);

    init();

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;

        G[u].push_back(v);
        source[v] = false;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (source[i]) {
            dfs(i);
            cnt++;
        }
    }


    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            for (int j : G[i]) {
                if (!vis[j]) {
                    unite(i, j);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (sz[i] > 1) cnt++;
    }

    cout << cnt;
}