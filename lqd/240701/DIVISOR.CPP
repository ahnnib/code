#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    freopen("DIVISOR.INP", "r", stdin);
    freopen("DIVISOR.OUT", "w", stdout);

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    while (n--) {
        ll a; cin >> a;
        int cnt = 0;
        for (ll i = 1; i * i <= a; i++) {
            if (a % i == 0) {
                cnt += 1 + (i != a/i);
            }
        }
        cout << cnt << '\n';
    }
}
