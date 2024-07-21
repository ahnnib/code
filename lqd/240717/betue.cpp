#include <iostream>
#include <cstdio>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

ll n, m, a[300000];

ll kt(ll x) {
    ll res = 0;
    for (int i = 0; i < m; i++) {
        res += a[i] / x;
        if (a[i] % x != 0) res++;
    }
    return res;
}
int main() {
    freopen("betue.inp", "r", stdin);
    freopen("betue.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i];
    ll l = 1, r = 1e9, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (kt(mid) <= n) r = mid - 1;
        else l = mid + 1;
    }
    cout << l;
}