#include <iostream>
using namespace std;

const int N = 2e5 + 7;
int parent[N], sz[N];

void init() {
    for (int i = 1; i < N; i++) parent[i] = i, sz[i] = 1;
}
int find(int u) {
    return (parent[u] == u ? u : (parent[u] = find(parent[u])));
}
bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return 0;

    if (sz[x] < sz[y]) swap(x, y);
    parent[y] = x;
    sz[x] += sz[y];

    return 1;
}
bool connected(int x, int y) {
    return find(x) == find(y);
}

int main()
{
    // Driver code
    int n, m; cin >> n >> m;

    int components = n, max_sz = 0;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;

        components -= unite(u, v);
        max_sz = max(max_sz, sz[find(u)]);

        cout << components << ' ' << max_sz << '\n';
    }

    return 0;
}