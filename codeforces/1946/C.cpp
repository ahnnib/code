#include <vector>
#include <iostream>
using namespace std;

#define debug cout << "dfad\n";

void solve() {
    int n, k; cin >> n >> k;

    vector< vector<int> > G(n+1);
    vector<int> sz(n+1);

    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v); G[v].push_back(u);
    }
    /*
    cnp kết quả
    có thể cắt cây thành TỐI ĐA bao nhiêu tplt sao cho mỗi tp có ít nhất x đỉnh
    */
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        int tplt = 0;
        auto dfs = [&](auto&& self, int u, int p) -> int {
            int sz = 1;
            for (int v : G[u]) {
                if (v != p) sz += self(self, v, u);
            }
            if (sz >= mid) { tplt++; return 0; }
            return sz;
        };

        dfs(dfs, 1, -1);

        if (tplt >= k + 1) l = mid;
        else r = mid - 1;
    }

    cout << l;

    cout << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    long long NTT; cin >> NTT; while (NTT--) {
        solve();
    }
}