#include <iostream>
#include <cstdio>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

ll n, m, a[1000000];

ll kt(ll x) {
    ll res = 0;
    for (int i = 0; i < n; i++) res += max(0ll, a[i] - x);
    return res;
}
int main() {
    freopen("wood.inp", "r", stdin);
    freopen("wood.out", "w", stdout);
    cin >> n >> m; for (int i = 0; i < n; i++) cin >> a[i];
    ll l = 0, r = 1e9, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (kt(mid) < m) r = mid - 1;
        else l = mid + 1;
    }
    cout << r;
}