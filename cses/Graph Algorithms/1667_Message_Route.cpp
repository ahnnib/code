#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5 + 1;

vector<int> dsk[N];
vector<bool> vis(N);
queue<int> q;
vector<int> pre(N);

void bfs(int root)
{
    vis[root] = true;
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
                pre[child] = node;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int _ = 0; _ < m; _++)
    {
        int a, b;
        cin >> a >> b;

        dsk[a].push_back(b); dsk[b].push_back(a);
    }

    bfs(1);

    // vis[n] = 0 <=> pre[n] = 0 -> infinity while
    if (!vis[n]) return cout << "IMPOSSIBLE", 0;

    vector<int> ans;
    int node = n;
    while (node != 1)
    {
        ans.push_back(node);
        node = pre[node];
    }
    ans.push_back(1);

    reverse(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << ' ';
}
