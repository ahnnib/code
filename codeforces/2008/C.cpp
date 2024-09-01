#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

void solve() {
    ll l, r; cin >> l >> r;
    ll x = 1, y = 1e9, mid;
    while (x <= y) {
        mid = (x + y) >> 1;
        if (l + mid * (mid - 1) / 2 <= r) x = mid + 1;
        else y = mid - 1;
    }
    cout << y << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}