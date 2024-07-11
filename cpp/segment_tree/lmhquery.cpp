#include <iostream>

#define debug cout << "dfad\n";

const int MAX = 1e5 + 7;
int n, m, st[4 * MAX]; char query; int k, u;

void update(int id, int l, int r, int i, int val) { // set i to val
    // base case
    if (i < l || i > r) return;
    if (l == r) { st[id] = val; return; }

    int mid = (l + r) >> 1;
    update(2*id, l, mid, i, val); update(2*id+1, mid+1, r, i, val);

    st[id] = std::max(st[2*id], st[2*id+1]);
}
int get(int id, int l, int r, int x, int y) { // returns max in range[x, y]
    // base case
    if (l > y || r < x) return -1; // range [l, r] is not in [x, y]
    if (x <= l && r <= y) return st[id]; // range [l, r] is in [x, y]

    int mid = (l + r) >> 1;
    return std::max(get(2*id, l, mid, x, y), get(2*id+1, mid+1, r, x, y));
}

int main()
{
    std::cin >> n >> m;

    while (m--)
    {
        std::cin >> query >> k >> u;

        if (query == 'S') update(1, 1, n, k, u);
        if (query == 'Q') std::cout << get(1, 1, n, k, u) << '\n';
    }
}