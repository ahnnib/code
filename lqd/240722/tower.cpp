#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define debug cout << "dfad\n";

const int N = 1e5 + 7;
int st[4 * N];
int get(int i, int l, int r, int x, int y) {
    if (l > y || r < x) return 0;
    if (x <= l && r <= y) return st[i];
    int mid = (l + r) >> 1;
    return max(get(2 * i, l, mid, x, y), get(2 * i + 1, mid + 1, r, x, y));
}
void update(int i, int l, int r, int p, int val) {
    if (l == r) { st[i] = val; return; }
    int mid = (l + r) >> 1;
    if (p <= mid) update(2 * i, l, mid, p, val);
    else update(2 * i + 1, mid + 1, r, p, val);
    st[i] = max(st[2 * i], st[2 * i + 1]);
}
signed main() {
    freopen("tower.inp", "r", stdin);
    freopen("tower.out", "w", stdout);
    int n; cin >> n;
    int r[n+1] = {}, h[n+1] = {}; for (int i = 1; i <= n; i++) cin >> r[i] >> h[i];
    int res = 0;
    for (int i = n; i >= 1; i--) {
        // int t = 0;
        // for (int j = 1; j < r[i]; j++) t = max(t, dp[j]);
        // dp[r[i]] = max(dp[r[i]], t + h[i]);
        int t = get(1, 1, n, 1, r[i] - 1);
        update(1, 1, n, r[i], t + h[i]);
    }
    cout << st[1];
    // for (int i = 1; i <= 100; i++) cout << dp[i] << ' '; cout << '\n';
    // for (int i = 1; i <= 100; i++) cout << st[i] << ' ';
}