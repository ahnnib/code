#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

ll n, b[100001], c[100001];

int main() {
    freopen("nksgame.inp", "r", stdin);
    freopen("nksgame.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    sort(b + 1, b + n + 1); sort(c + 1, c + n + 1);
    ll res = 1e18;
    for (int i = 1; i <= n; i++) {
        // cout << i << ' ';
        int l = 1, r = n, mid; while (l <= r) {
            mid = (l + r) >> 1; // ptu cuoi cung < -b[i]
            if (c[mid] < -b[i]) l = mid + 1;
            else r = mid - 1;
        }
        // cout << l << ' ' << r << " | ";
        if (r > 0) res = min(res, abs(b[i] + c[r]));
        res = min(res, abs(b[i] + c[l]));
        l = 1, r = n; while (l <= r) {
            mid = (l + r) >> 1; // ptu dau tien > -b[i]
            if (c[mid] <= -b[i]) l = mid + 1;
            else r = mid - 1;
        }
        if (l <= n) res = min(res, abs(b[i] + c[l]));
        // cout << l << ' ' << r << '\n';
    }
    cout << res;
}