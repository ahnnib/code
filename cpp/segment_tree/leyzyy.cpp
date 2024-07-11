/*
https://oj.vnoi.info/problem/segtree_itlazy
1 x y: FOR(i, x, y) a[x] += y
2 l r: \sum{a[l] -> a[r]}
*/
#include <iostream>
using namespace std;

const int MAX = 1e5 + 7;
const int INF = 2147483647;

int a[MAX];

long long st[4 * MAX], lazy[4 * MAX];

void build(int id, int l, int r) {
    if (l == r) {st[id] = a[l]; return; }
    int mid = (l + r) >> 1;
    build(2*id, l, mid); build(2*id+1, mid+1, r);
    st[id] = max(st[2*id], st[2*id+1]);
}
void fix(int id, int l, int r) {
    if (!lazy[id]) return;
    st[id] += lazy[id];

    if (l != r) {
        lazy[2*id] += lazy[id];
        lazy[2*id+1] += lazy[id];
    }
    lazy[id] = 0;
}
void update(int id, int l, int r, int u, int v, int val) {
    fix(id, l, r);
    if (l > v || r < u) return;
    if (u <= l && r <= v) {
        lazy[id] += val; fix(id, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(2*id, l, mid, u, v, val); update(2*id+1, mid+1, r, u, v, val);
    st[id] = max(st[2*id], st[2*id+1]);
}
long long get(int id, int l, int r, int u, int v) {
    fix(id, l, r);
    if (l > v || r < u) return -INF;
    if (u <= l && r <= v) return st[id];

    int mid = (l + r) >> 1;
    return max(get(2*id, l, mid, u, v), get(2*id+1, mid+1, r, u, v));
}

int main()
{
    int n; cin >> n; for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);

    int q; cin >> q; while (q--)
    {
        int query, x, y; cin >> query >> x >> y;

        if (query == 1) { int k; cin >> k; update(1, 1, n, x, y, k); }
        if (query == 2) cout << get(1, 1, n, x, y) << '\n';
    }
}