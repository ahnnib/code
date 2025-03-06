#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    freopen("keo.inp", "r", stdin);
    freopen("keo.out", "w", stdout);
    ll n; cin >> n;
    ll bound = n + 1 >> 1;

    auto check = [&](ll k) -> bool {
        ll vasya = 0;
        ll n1 = n;
        while (1) {
            if (n1 < k) break;
            n1 -= k;
            vasya += k;
            n1 -= n1 / 10;
        }
        return vasya + n1 >= bound;
    };

    ll l = 1, r = 1e18, mid;
    while (l <= r) {
        mid = l + (r - l >> 1);
        if (check(mid)) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << l;
}