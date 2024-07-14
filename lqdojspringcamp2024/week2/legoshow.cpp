#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    #ifndef ONLINE_JUDGE
    #else
    freopen("legoshow.inp", "r", stdin);
    freopen("legoshow.out", "w", stdout);
    #endif
    int n, k; cin >> n >> k;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n-1];

    int f[n], g[n], u = n-1, v = 0;
    // mô hình thứ i là mô hình cuối cùng ở phòng -> có g[i] mô hình trước i
    // mô hình thứ i là mô hình đầu tiên ở phòng -> có f[i] mô hình sau i
    for (int i = 0; i < n; i++) {
        while (v < n && a[v] - a[i] <= k) v++;
        f[i] = v - i;
        if (i > 0) f[i] = max(f[i], f[i-1]);
    }
    for (int i = n-1; i >= 0; i--) {
        while (u >= 0 && a[i] - a[u] <= k) u--;
        g[i] = i - u;
        if (i < n-1) g[i] = max(g[i], g[i+1]);
    }
    int res = 0;
    for (int i = 0; i < n; i++) res = max(res, f[i] + g[i-1]);
    cout << res;
}
