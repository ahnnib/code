#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

const int MAX = 1e5 + 1;
bool vis[MAX];
int dist[MAX];
queue<int> q;

vector<int> dsk[MAX];

void bfs(int root)
{
    vis[root] = true;
    dist[root] = 0;
    q.push(root);

    while (!q.empty())
    {
        int node = q.front(); q.pop();
        for (int child : dsk[node])
        {
            if (vis[child] == true)
                continue;
            else
            {
                vis[child] = true;
                q.push(child);
                dist[child] = dist[node] + 1;
            }
        }
    }
}

int main()
{
    int n, m, s;
    cin >> n >> m >> s;

    for (int _ = 0; _ < m; _++)
    {
        int u, v;
        cin >> u >> v;

        dsk[u].push_back(v); dsk[v].push_back(u);
    }

    bfs(s);

    set< pair<int, int> > res;
    for (int i = 1; i <= n; i++)
        if (vis[i]) res.insert({dist[i], i});

    cout << '\n';
    for (pair<int, int> p : res) cout << p.second << ' ' << p.first << '\n';
}