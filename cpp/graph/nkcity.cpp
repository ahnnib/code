/*
https://oj.vnoi.info/problem/nkcity
*/
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

#define f first
#define s second

struct DSU {
    vector<int> p, lvl;
    void init(int n) {
        p.resize(n+1, 0);
        iota(p.begin(), p.begin() + n + 1, 0);
        lvl.assign(n+1, 0);
    }
    int find(int u) { return (p[u] == u ? u : p[u] = find(p[u])); }
    bool unite(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return 0;
        if (lvl[u] < lvl[v]) swap(u, v);
        if (lvl[u] == lvl[v]) lvl[u]++;
        p[v] = u;
        return 1;
    }
} dsu;

int main()
{
    int n, m; cin >> n >> m;

    pair<int, pair<int, int> > E[m];
    for (int i = 0; i < m; i++) {
        cin >> E[i].s.f >> E[i].s.s >> E[i].f;
    }

    sort(E, E + m);

    // Kruskal's algorithm
    int res = -2147483647 - 1;
    dsu.init(n);
    for (auto e : E) {
        if (!dsu.unite(e.s.f, e.s.s)) continue;
        else res = max(res, e.f);
    }

    cout << res;
}