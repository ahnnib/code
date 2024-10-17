#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const int N = 1e5 + 1;
int n, k;
int d[N], vt[N], dp[N];

int tree[4 * N];
void update(int id, int l, int r, int p, int v) {

    if (l > p || r < p) return;
    if (l == r) {
        tree[id] = v;
        return;
    }

    int m = (l + r) >> 1;

    update(2*id, l, m, p, v);
    update(2*id+1, m+1, r, p, v);

    tree[id] = max(tree[2*id], tree[2*id+1]);
}
int get(int id, int l, int r, int x, int y) {

    if (l > y || r < x) return 0;
    if (x <= l && r <= y) return tree[id];

    int m = (l + r) >> 1;

    return max(get(2*id, l, m, x, y), \
               get(2*id+1, m+1, r, x, y));
}

int main() {
    freopen("noidiem.inp", "r", stdin);
    freopen("noidiem.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        vt[d[i]] = i;
    }

    if (k >= n-1) {
        cout << n;
    }

    else {
        for (int i = 1; i <= n; i++) {

            for (int j = min(n, i+k); j >= max(1, i-k); j--) {

                int t = get(1, 1, n, 1, vt[j] - 1) + 1;
                dp[vt[j]] = max(dp[vt[j]], t);
            }

            for (int j = min(n, i+k); j >= max(1, i-k); j--) {

                update(1, 1, n, vt[j], dp[vt[j]]);
            }
        }
    }

    cout << tree[1];
}