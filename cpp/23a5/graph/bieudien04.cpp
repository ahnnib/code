#include <iostream>
#include <vector>
using namespace std;

int main()
{
    short n, m;
    cin >> n >> m;
    int deg[n+1] = {};
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        deg[u]++;
        deg[v]++;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << deg[i] << ' ';
    }
}