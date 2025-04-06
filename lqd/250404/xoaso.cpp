#include <iostream>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

bool prime(ll n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}
int main() {
    string n; cin >> n;
    ll res = 0;
    for (ll msk = (1ll << n.size()) - 1; msk >= 0; msk--) {
        ll t = msk;
        ll num = 0;
        for (int i = 0; t; t >>= 1, i++) {
            if (t & 1) num = num * 10 + n[i] - 48;
        }
        if (prime(num)) res = max(res, num);
    }
    cout << res;
}