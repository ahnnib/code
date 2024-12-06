#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const int N = 1e5 + 1;
const int INF = 1000000000;
int n, m, s, t, x, y, w;
vector < vector < pair < int, int > > > adj(N);

vector<int> d(N, INF);
vector<bool> vis(N, false);

void dijkstra(int s, vector<int> &d) {
    int n = adj.size();

    d[s] = 0;
    set < pair < int, int > > q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
}

int main() {
    cin >> n >> m >> s >> t;

    for (int i = 0; i < m; i++) {

        cin >> x >> y >> w;

        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    dijkstra(s, d);

    if (d[t] == INF) cout << -1;
    else cout << d[t];
}
/*
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

const int MAX = 1e5 + 1;
int dist[MAX];
queue<int> q;

vector<int> dsk[MAX];

void bfs(int root)
{
    dist[root] = 0;
    q.push(root);

    while (!q.empty())
    {
        int node = q.front(); q.pop();
        for (int child : dsk[node])
        {
            if (dist[child] > dist[node] + 1) {
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
*/