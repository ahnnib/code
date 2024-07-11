#include <iostream>
using namespace std;

#define debug cout << "dfad\n";

const int MAX = 2e5 + 7;

int n, q, a[MAX];

long long st[4 * MAX];

void build(int id, int l, int r) {
    // base case
    if (l == r) { st[id] = a[l]; return; }

    int mid = (l + r) >> 1;
    build(2*id, l, mid); build(2*id+1, mid+1, r);
    st[id] = st[2*id] + st[2*id+1];
}
void update(int id, int l, int r, int i, int val) {
    // base case
    if (i < l || i > r) return; // position i is out of range [l, r]
    if (l == r) { st[id] = val; return; }

    int mid = (l + r) >> 1;
    update(2*id, l, mid, i, val); update(2*id+1, mid+1, r, i, val);

    st[id] = st[2*id] + st[2*id+1];
}
long long get(int id, int l, int r, int u, int v) {
    // base case
    if (l > v || r < u) return 0; // [l, r] is not in [u, v]
    if (u <= l && r <= v) return st[id];

    int mid = (l + r) >> 1;
    return get(2*id, l, mid, u, v) + get(2*id+1, mid+1, r, u, v);
}

int main()
{
    cin >> n >> q; for (int i = 1; i <= n; i++) cin >> a[i];

    build (1, 1, n);

    while (q--)
    {
        int query, x, y; cin >> query >> x >> y;
        if (query == 1) update(1, 1, n, x, y);
        if (query == 2) cout << get(1, 1, n, x, y) << '\n';
    }
}