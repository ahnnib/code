/*
https://lqdoj.edu.vn/problem/lca
*/
#include <iostream>
#include <vector>
using namespace std;

#define debug cout << "dfad\n";
const int N = 1001;
vector<int> p, h(N);

void init() {
    p.resize(N, 0);
    h.assign(N, 1);
}

int lca(int u, int v) {
    // h[u] >= h[v]
    if (h[u] < h[v]) swap(u, v);
    // đi từ u đến u' sao cho h[u'] = h[v]
    while (h[u] > h[v]) u = p[u];
    // đồng thời đi u, v đến cha
    while (u != v) u = p[u], v = p[v];
    return u;
}

void solve(int tc) {
    cout << "Case " << tc << ":\n";
    int n; cin >> n; for (int i = 1; i <= n; i++) {
        int k; cin >> k; while (k--) {
            int id; cin >> id;
            p[id] = i; h[id] = h[i] + 1;
        }
    }
    int q; cin >> q; while (q--) {
        int u, v; cin >> u >> v; cout << lca(u, v) << '\n';
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    init();

    int t; cin >> t; for (int tc = 1; tc <= t; tc++) {
        solve(tc);
    }
}