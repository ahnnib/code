#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 7;
int n, m;
vector<bool> vis(N);
vector<int> G[N];

void dfs(int u) {
    vis[u] = 1;
    for (int v : G[u]) if (!vis[v]) dfs(v);
}

int main()
{
    cin >> n >> m; for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v); G[v].push_back(u);
    }

    vector<int> res;
    for (int node = 1; node <= n; node++) {
        if (!vis[node]) dfs(node), res.push_back(node);
    }

    cout << res.size() / 2 + (res.size() % 2) << '\n';
    for (int i = 0; i < res.size(); i += 2) {
        cout << res[i] << ' ' << res[i+1] << '\n';
    }
}