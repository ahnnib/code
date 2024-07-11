#include <iostream>
using namespace std;

#define ll long long

void solve() {
    ll x, y, z; ll k; cin >> x >> y >> z >> k;
    ll res = 0;
    for (ll a = 1; a <= x; a++) {
        for (ll b = 1; b <= y; b++) {
            if (k % (a*b) == 0) {
                // c = k / ab
                ll c = k / a / b;
                if (c > z) continue;
                res = max(res, (x - a + 1) * (y - b + 1) * (z - c + 1));
            }
        }
    }
    cout << res << '\n';
}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}