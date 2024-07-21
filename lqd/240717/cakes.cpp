#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

ll s; int n, t[20];
ll kt(ll x) {
    ll res = 0; for (int i = 0; i < n; i++) res += x / t[i];
    return res;
}
int main() {
    freopen("cakes.inp", "r", stdin);
    freopen("cakes.out", "w", stdout);
    cin >> s >> n; for (int i = 0; i < n; i++) cin >> t[i];
    ll l = 1, r = 1e15, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (kt(mid) >= s) r = mid - 1;
        else l = mid + 1;
    }
    cout << l;
}