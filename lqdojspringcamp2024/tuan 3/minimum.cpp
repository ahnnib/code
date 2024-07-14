#include <iostream>
using namespace std;

int n, k, a[500001];

int s[2000005];
void build(int id, int l, int r) {
    if (l == r) {s[id] = a[l]; return; }
    int mid = (l + r) >> 1;
    build(2*id, l, mid); build(2*id+1, mid+1, r);
    s[id] = min(s[2*id], s[2*id+1]);
}
int get(int id, int l, int r, int x, int y) {
    if (x > r || y < l) return 1e6;
    if (x <= l && r <= y) return s[id];
    int mid = (l + r) >> 1;
    return min(get(2*id, l, mid, x, y), get(2*id+1, mid+1, r, x, y));
}
int _get(int l, int r) { return get(1, 1, n, l, r); }

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("minimum.inp", "r", stdin);
    freopen("minimum.out", "w", stdout);
    #endif

    cin >> n >> k; for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);
    for (int i = 1; i <= n - k + 1; i++) {
        cout << _get(i, i + k - 1) << '\n';
    }
}