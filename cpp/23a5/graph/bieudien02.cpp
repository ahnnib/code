#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // adjlist
    short n, m;
    cin >> n >> m;
    vector<int> adjlist[n + 1];
    for (int i = 0; i < m; i++)
    {
        short u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        if (adjlist[i].empty()) adjlist[i].push_back(0);
        cout << i << ": ";
        sort(adjlist[i].begin(), adjlist[i].end());
        for (auto j : adjlist[i]) cout << j << ' ';
        cout << '\n';
    }
}