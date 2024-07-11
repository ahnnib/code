#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    bool adjmat[n][n] = {};
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjmat[u-1][v-1] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << adjmat[i][j] << ' ';
        cout << '\n';
    }
}