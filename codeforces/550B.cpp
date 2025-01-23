#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    int n, l, r, x; cin >> n >> l >> r >> x;
    int c[n]; for (int i = 0; i < n; i++) cin >> c[i];

    bool bit[n];
    int cnt = 0;
    for (int mask = 0; mask < 1<<n; ++mask) {
        for (int j = n-1; j >= 0; j--) {
            if (1<<j & mask) bit[j] = 1;
            else bit[j] = 0;
        }

        int mx = 0, mn = 1e6, sum = 0;
        for (int j = 0; j < n; j++) {
            if (bit[j]) {
                mx = max(mx, c[j]);
                mn = min(mn, c[j]);
                sum += c[j];
            }
        }

        if (l <= sum && sum <= r && mx - mn >= x) cnt++;
    }
    cout << cnt;
}