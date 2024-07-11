#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    int n, m; cin >> n >> m;
    int a[n+1] = {}, b[m+1] = {};
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(a + 1, a + n + 1); sort(b + 1, b + m + 1);

    // binary search
    // int res = 2e9;
    // for (int i = 1; i <= n; i++) {
    //     int l = 1, r = m, mid;
    //     while (l <= r) {
    //         mid = (l + r) >> 1;
    //         if (b[mid] <= a[i]) l = mid + 1;
    //         else r = mid - 1;
    //     }
    //     if (1 <= r && r <= m) res = min(res, abs(a[i] - b[r]));
    //     l = 1, r = m; while (l <= r) {
    //         mid = (l + r) >> 1;
    //         if (b[mid] < a[i]) l = mid + 1;
    //         else r = mid - 1;
    //     }
    //     if (1 <= l && l <= m) res = min(res, abs(a[i] - b[l]));
    // }
    // cout << res;

    // 2-pointer
    int j = 1, res = 2e9;
    for (int i = 1; i <= n; i++) {
        while (j < m && b[j] < a[i]) j++;
        res = min(res, abs(a[i] - b[j]));
        if (j > 1) res = min(res, abs(a[i] - b[j-1]));
    }
    cout << res;
}