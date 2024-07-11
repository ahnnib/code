#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge { int u, v, w, pos; };

bool cmp(Edge a, Edge b)
{
    if (a.w != b.w) return a.w < b.w;
    return a.pos < b.pos;
}

int main()
{
    short n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end(), cmp);

    for (auto i : edges) cout << i.u << ' ' << i.v << ' ' << i.w << '\n';
}