#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll n, m, k;

int main() {
    cin >> n >> m >> k;

    if (n > m) swap(n, m);

    auto cnt = [&](ll x) {
        ll res = 0;
        for (ll i = 1; i <= n; i++) {
            res += max(0ll, min((ll)sqrt(x - i*i), m));
        }
        return res;
    };

    ll l = 1, r = 1ll<<62, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (cnt(mid) < k)
            l = mid + 1;
        else r = mid - 1;
    }
    cout << l;
}