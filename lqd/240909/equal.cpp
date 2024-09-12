#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

ll a[1000000];
int main() {
    freopen("equal.inp", "r", stdin);
    freopen("equal.out", "w", stdout);
    ll n; cin >> n;
    ll sum = 0, sumsq = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        sumsq += a[i] * a[i];
    }
    ll res = 1e18;
    for (int u = -1e6; u <= 1e6; u++) {
        res = min(res, sumsq + n * u * u - 2 * u * sum);
    }
    cout << res;
}
