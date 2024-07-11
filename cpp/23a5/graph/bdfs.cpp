#include <iostream>
#include <vector>
using namespace std;

bool vis[(int)1e5 + 1];
vector<int> dsk[(int)1e5 + 1];

void dfs(int node)
{
    vis[node] = true;
    for (auto i : dsk[node])
    {
        if (!vis[i]) dfs(i);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int _ = 0; _ < m; _++)
    {
        int u, v;
        cin >> u >> v;

        dsk[u].push_back(v);
        dsk[v].push_back(u);
    }

    int ans = 0;
    for (int node = 1; node <= n; node++)
    {
        if (!vis[node]) ans++, dfs(node);
    }

    cout << ans;
}