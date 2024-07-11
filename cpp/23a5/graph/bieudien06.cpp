#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    bool mat[n+1][n+1] = {};
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        mat[u][v] = mat[v][u] = 1;
    }
    int q;
    cin >> q;
    while (q--)
    {
        short s, t;
        cin >> s >> t;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (mat[s][i] == mat[t][i] && mat[t][i] == 1) // i la ban chung cua s, t <=> co duong di tu i toi s, t
                cnt++;
        }
        cout << cnt << '\n';
    }
}