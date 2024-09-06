#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define debug coug << "dfad\n";

const int N = 2e5 + 7;
int parent[N], sz[N];

void init(int n) {
    for (int i = 1; i <= n; i++) parent[i] = i, sz[i] = 1;
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

int main() {
    int n; cin >> n;
    init(n);
    vector < pair <int, int> > v(n);
    for (int i = 1; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    vector <int> query;
    vector <bool> mark(n, false);
    int q; cin >> q; while (q--) {
        int i; cin >> i;
        query.push_back(i);
        mark[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (!mark[i]) unite(v[i].first, v[i].second);
    }
    vector<ll> res;
    for (int i = query.size()-1; i >= 0; i--) {
        int id = query[i];
        int x = find(v[id].first),
            y = find(v[id].second);
        res.push_back(1ll * sz[x] * sz[y]);
        unite(x, y);
    }
    for (int i = res.size()-1; i >= 0; i--) {
        cout << res[i] << '\n';
    }
}