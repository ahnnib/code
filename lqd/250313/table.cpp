#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("table.inp", "r", stdin);
    freopen("table.out", "w", stdout);
    int m, n; cin >> m >> n;
    int a[m+1][n+1];
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            string x; cin >> x; int t;
            if (x == "A") t = 1;
            else if (x == "J") t = 11;
            else if (x == "Q") t = 12;
            else if (x == "K") t = 13;
            else if (x == "10") t = 10;
            else t = x[0] - '0';
            a[i][j] = t;
        }
    }

    int sum[m+1][n+1] = {};
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }

    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int q; cin >> q; while (q--) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        cout << sum[u][v] - sum[u][y-1] - sum[x-1][v] + sum[x-1][y-1] << '\n';
    }
}