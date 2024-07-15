#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    freopen("camdien.inp", "r", stdin);
    freopen("camdien.out", "w", stdout);
    int n, m; cin >> n >> m; int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    if (m == 1) return cout << 0, 0; // cam vao tuong
    sort(a, a + n, greater<int>());
    ll s = 1, i = 0; for (; i < n; i++) {
        if (s >= m) { i--; break; }
        s = s - 1 + a[i];
    }
    if (s < m) cout << -1;
    else cout << i + 1;
}