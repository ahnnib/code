#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    freopen("orange.inp", "r", stdin);
    freopen("orange.out", "w", stdout);

    int n; cin >> n;
    ll a[n+1] = {}; for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1, greater<int>());

    ll res = 0;
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        ll cur = a[i] * i;
        if (a[i] == a[i-1]) {
            cnt++;
            cur -= a[i] * (cnt - 1);
        }
        else {
            cnt = 1;
        }
        res = max(res, cur);
        if (i != n) {
            if (a[i] - a[i+1] > 1) {
                res = max(res, (a[i] - 1) * i);
            }
        }
        // cout << res << ' ';
    }
    res = max(res, (a[n] - 1) * n);
    cout << res;
}