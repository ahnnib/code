#include <iostream>
using namespace std;

#define debug cout << "dfad\n";

const int MAX = 2e5 + 7;
const int INF = 2147483647;

int a[MAX];
int st[4 * MAX];

void build(int id, int l, int r) {
    // base case
    if (l == r) { st[id] = a[l]; return; }

    // debug
    int mid = (l + r) >> 1;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);

    st[id] = min(st[2*id], st[2*id+1]);
}
int get(int id, int l, int r, int x, int y) { // find minimum value in range [x, y]
    // base case
    if (l > y || r < x) return INF;
    if (l >= x && r <= y) return st[id]; // [l, r] is in [u, v]

    int mid = (l + r) >> 1;
    return min(get(2*id, l, mid, x, y),
               get(2*id+1, mid+1, r, x, y));
}

int main()
{
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);

    while (q--) {
        int a, b; cin >> a >> b;

        cout << get(1, 1, n, a, b) << '\n';
    }
}