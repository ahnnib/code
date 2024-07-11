/*
https://judge.yosupo.jp/problem/unionfind
*/
#include <iostream>
using namespace std;

const int MAX = 2e5 + 7;
int parent[MAX], sz[MAX];

void init() {
    for (int i = 0; i < MAX; i++) parent[i] = i, sz[i] = 1;
}
int find(int u) {
    return parent[u] == u ? u : (parent[u] = find(parent[u]));
}
bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return 0;
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    parent[y] = x;
    return 1;
}

bool connected(int u, int v) {
    return find(u) == find(v);
}

int main()
{
    int n, q; cin >> n >> q;
    init();
    while (q--) {
        int query, x, y; cin >> query >> x >> y;
        if (query == 0) unite(x, y);
        if (query == 1) cout << connected(x, y) << '\n';
    }
}