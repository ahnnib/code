#include <iostream>
#include <vector>
using namespace std;

int main()
{
    short n, m;
    cin >> n >> m;
    bool mat[n+1][n+1] = {};
    for (int i = 0; i < m; i++)
    {
        short u, v;
        cin >> u >> v;

        mat[u][v] = mat[v][u] = 1;
    }
    for (int i = 1; i <= n; i++) // khử khuyên
        mat[i][i] = 0;

    vector<int> graph[n+1];

    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= n; v++)
        {
            if (mat[u][v]) graph[u].push_back(v);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        if (graph[i].empty()) graph[i].push_back(0);
        for (auto j : graph[i]) cout << j << ' ';
        cout << '\n';
    }
}