#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1e5 + 1;
bool vis[N];
int pre[N];
vector<int> dsk[N];
queue<int> q;

void bfs(int root)
{
    vis[root] = 1; q.push(root);

    while (!q.empty())
    {
        int node = q.front(); q.pop();
        for (int child : dsk[node])
        {
            if (vis[child]) continue;
            else {
                vis[child] = 1;
                q.push(child);
                pre[child] = node;
            }
        }
    }
}

int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        dsk[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
        sort(dsk[i].begin(), dsk[i].end());

    // for (int i = 0; i <= n; i++)
    // {
    //     cout << i << ": ";
    //     for (auto j : dsk[i]) cout << j << ' ';
    //     cout << '\n';
    // }

    bfs(s);

    vector<int> ans;
    int node = t;
    while (node != s)
    {
        ans.push_back(node);
        node = pre[node];
    } ans.push_back(s);

    reverse(begin(ans), end(ans));

    for (auto i : ans) cout << i << ' ';
}