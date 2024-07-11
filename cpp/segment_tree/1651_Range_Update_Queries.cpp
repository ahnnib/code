#include <iostream>
using namespace std;

const int MAX = 2e5 + 7;

int a[MAX];

long long st[4 * MAX];

void build(int id, int l, int r) {
    if (l == r) { st[id] = a[l]; return; }
    int mid = (l + r) >> 1;
    build(2*id, l, mid); build(2*id+1, mid+1, r);
    st[id] = st[2*id] + st[2*id+1];
}
void update(int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) { st[id] += val; return; }
    int mid = (l + r) >> 1;
    update(2*id, l, mid, pos, val); update(2*id+1, mid+1, r, pos, val);
    // cout << l << ' ' << r << ' ' << ' ' << 2*id << ' ' << 2*id+1 << ' ' << st[2*id] << ' ' << st[2*id+1] << '\n';
    st[id] = st[2*id] + st[2*id+1];
}
long long get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    return get(2*id, l, mid, u, v) + get(2*id+1, mid+1, r, u, v);
}

/*
quy về bài toán
1 x y u: cập  nhật [x, y] lên u
2 k: phần tử thứ k = tổng mảng hiệu từ 1 tới k
*/
int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int n, q; cin >> n >> q; for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(1, 1, n, i, a[i] - a[i-1]);
    }


    // for (int i = 1; i <= 4 * n; i++) cout << st[i] << ' '; cout << '\n';
    // update(1, 1, n, 2, 1);
    // for (int i = 1; i <= 4 * n; i++) cout << st[i] << ' '; cout << '\n';
    // update(1, 1, n, 5+1, -1);
    // for (int i = 1; i <= 4 * n; i++) cout << st[i] << ' '; cout << '\n';
    while (q--) {
        int query; cin >> query;
        if (query == 1) {
            int x, y, u; cin >> x >> y >> u;
            update(1, 1, n, x, u); // st[x] += u;
            update(1, 1, n, y+1, -u); // st[y+1] += -u;
        }
        if (query == 2) { int k; cin >> k; cout << get(1, 1, n, 1, k) << '\n'; }
    }
}
/*
8 3
3 2 4 5 1 1 5 3
3 -1 2 1 -4 0 4 -2

2 4
1 2 5 1
3 3 5 6 2 1 5 3
3 0 2 1 -4 -1 4 -2

2 4

5
6
*/