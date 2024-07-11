#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 1;

bool vis[N];
vector<int> dsk[N];

void dfs(int node)
{
    vis[node] = 1;
    for (auto i : dsk[node])
        if (!vis[i]) dfs(i);
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        dsk[a].push_back(b); dsk[b].push_back(a);
    }

    vector<int> nodes;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            nodes.push_back(i);
        }
    }

    cout << nodes.size()-1 << '\n';
    for (int i = 1; i < nodes.size(); i++)
    {
        cout << nodes[i-1] << ' ' << nodes[i] << '\n';
    }
}