#include <iostream>
#include <deque>
using namespace std;

int n, k, a[500001];

// int s[2000005];
// void build(int id, int l, int r) {
//     if (l == r) {s[id] = a[l]; return; }
//     int mid = (l + r) >> 1;
//     build(2*id, l, mid); build(2*id+1, mid+1, r);
//     s[id] = min(s[2*id], s[2*id+1]);
// }
// int get(int id, int l, int r, int x, int y) {
//     if (x > r || y < l) return 1e6;
//     if (x <= l && r <= y) return s[id];
//     int mid = (l + r) >> 1;
//     return min(get(2*id, l, mid, x, y), get(2*id+1, mid+1, r, x, y));
// }
// int _get(int l, int r) { return get(1, 1, n, l, r); }

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("minimum.inp", "r", stdin);
    freopen("minimum.out", "w", stdout);
    #endif
    /*
    build(1, 1, n);
    for (int i = 1; i <= n - k + 1; i++) {
        cout << _get(i, i + k - 1) << '\n';
    }
    */
    // O(n)
    cin >> n >> k; for (int i = 0; i < n; i++) cin >> a[i];
    deque<int> dq;
    for (int i = 0; i < n; ++i) {
        // remove elements out of current window
        while (!dq.empty() && i - dq.front() + 1 > k) {
            dq.pop_front();
        }
        // remove elements that are useless i.e. smaller than a[i]
        while (!dq.empty() && a[dq.back()] >= a[i]) {
            dq.pop_back();
        }
        // push current element to deque
        dq.push_back(i);
        // only print the result when a window is finished
        if (i >= k-1) cout << a[dq.front()] << '\n';
    }
    /* O(n)
    chia day a ra thanh cac khuc do dai k, khuc cuoi do dai <= k
    i la vi tri dau cua khuc: (i-1)%k == 0 (ko dc viet i % k == 0 (vi k = 1))
    i la vi tri cuoi: i == n || i % k == 0
    f[i]: min tu dau khuc toi i, g[i]: min tu cuoi khuc toi i
    cin >> n >> k; for (int i = 1; i <= n; i++) cin >> a[i];
    int f[n+1] = {}; for (int i = 1; i <= n; i++) f[i] = (i-1)%k==0 ? a[i] : min(f[i-1], a[i]);
    int g[n+1] = {}; for (int i = n; i > 0; i--) g[i] = i==n || i%k==0 ? a[i] : min(g[i+1], a[i]);
    for (int i = 1; i+k-1 <= n; i++) cout << min(g[i], f[i+k-1]) << ' ';
    */
}