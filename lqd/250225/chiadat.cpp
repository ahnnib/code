#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int n;
bool grid[501][501];
int s[501][501];

int main() {
    freopen("chiadat.inp", "r", stdin);
    freopen("chiadat.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + (grid[i][j] == 1);
        }
    }

    auto getsum = [&](int x, int y, int u, int v) -> int {
        return s[u][v] - s[u][y-1] - s[x-1][v] + s[x-1][y-1];
    };

    int res = 1e9;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int mn = 1e9, mx = -1e9;
            mn = min(mn, getsum(1, 1, i, j));
            mn = min(mn, getsum(1, j+1, i, n));
            mn = min(mn, getsum(i+1, 1, n, j));
            mn = min(mn, getsum(i+1, j+1, n, n));

            mx = max(mx, getsum(1, 1, i, j));
            mx = max(mx, getsum(1, j+1, i, n));
            mx = max(mx, getsum(i+1, 1, n, j));
            mx = max(mx, getsum(i+1, j+1, n, n));

            res = min(res, mx - mn);
        }
    }

    cout << res;
}