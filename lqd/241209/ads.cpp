#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int n, m, u, v;
vector<int> G[2001];
vector<bool> vis(2001);

void dfs(int u) {
    vis[u] = 1;
    for (auto v : G[u]) {
        if (!vis[v]) dfs(v);
    }
}
int main() {
    freopen("ads.inp", "r", stdin);
    freopen("ads.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int tplt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            tplt++;
        }
    }

    cout << m - n + tplt;
}