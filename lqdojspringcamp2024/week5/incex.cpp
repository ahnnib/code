#include <bits/stdc++.h>
using ll = int64_t;
using namespace std;
#define dbg cout << "dfad\n";

const ll N = 1e18;
int n; ll l, r, a[18];

ll lcm(ll &x, ll &y) {
    // check tran so
    if (x / __gcd(x, y) >= N / y) return N + 1;
    return x / __gcd(x, y) * y;
}

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll L, t, res = 0; int nS;
    for (int i = 1; i < (1<<n); i++) {
        nS = 0; L = 1;
        for (int j = n-1; j >= 0; j--) {
            if (i & (1<<j)) {
                L = lcm(L, a[j]);
                nS++;
            }
        }
        t = r / L - (l-1) / L; // so lg boi cua L trong [l, r]
        res += (nS & 1 ? t : -t);
    }
    cout << r - l + 1 - res;
}