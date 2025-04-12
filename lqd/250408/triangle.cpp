#include <iostream>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll row[2001][2001] = {}, tri[2001][2001] = {}, sum[2001][2001] = {};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("triangle.inp", "r", stdin);
    freopen("triangle.out", "w", stdout);
    int m, n, k; cin >> m >> n >> k;
    int a[m+1][n+1] = {};
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            row[i][j] = row[i][j-1] + a[i][j];
            tri[i][j] = tri[i-1][j-1] + row[i][j-1] + a[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }

    auto box = [&](int i, int j, int u, int v) -> ll {
        return sum[u][v] - sum[u][j-1] - sum[i-1][v] + sum[i-1][j-1];
    };
    auto query = [&](int i, int j) -> ll {
        return tri[i + k - 1][j + k - 1] - tri[i - 1][j - 1] - box(i, 1, i + k - 1, j - 1);
    };

    ll res = -1e18;
    for (int i = 1; i + k - 1 <= m; i++) {
        for (int j = 1; j + k - 1 <= n; j++) {
            res = max(res, query(i, j));
        }
    }

    cout << res;
}