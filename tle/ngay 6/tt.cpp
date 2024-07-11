#include <iostream>
using namespace std;

#define int long long

const int MAX = 1e6 + 7;
long long st[4*MAX], a[MAX];

void build(int id, int l, int r) {
    if (l == r) { st[id] = a[l]; return; }
    int mid = (l + r) >> 1;
    build(id<<1, l, mid); build((id<<1)+1, mid+1, r);
    st[id] = st[id<<1] + st[(id<<1)+1];
}
void update(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return;
    // if (u <= l && r <= v) { st[id]>>=1; return; }
    if (l == r) { st[id] >>= 1; return; }
    int mid = (l + r) >> 1;
    update(id<<1, l, mid, u, v); update((id<<1)+1, mid+1, r, u, v);
    st[id] = st[id<<1] + st[(id<<1)+1];
}
int get() {
    return st[1];
}

signed main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("tt.inp", "r", stdin);
    freopen("tt.out", "w", stdout);
    #endif

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int n, q; cin >> n >> q; for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);
    // for (int i = 1; i <= 4 * n; i++) cout << st[i] << ' '; cout << '\n';

    while (q--) {
        int x, y; cin >> x >> y;
        update(1, 1, n, x, y);
        // for (int i = 1; i <= 4 * n; i++) cout << st[i] << ' '; cout << '\n';
        cout << get() << '\n';
    }
}
/*
5 3
6 12 7 9 11
45 25 20 18 7 9 11 6 12 0 0 0 0 0 0 0 0 0 0 0
1 4
27 12 15 18 7 4 11 6 12 0 0 0 0 0 0 0 0 0 0 0
16
3 5
28 21 7 18 3 4 11 6 12 0 0 0 0 0 0 0 0 0 0 0
10
2 3
20 13 7 12 1 4 11 6 6 0 0 0 0 0 0 0 0 0 0 0
7
*/