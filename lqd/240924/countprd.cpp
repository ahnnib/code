#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define dbg cout << "dfad\n";

int main() {
    freopen("COUNTPRD.INP", "r", stdin);
    freopen("COUNTPRD.OUT", "w", stdout);

    ll n; cin >> n;
    ll sqr = sqrt(n);
    ll cnt = 0;
    for (ll i = 2; i <= sqr; i++) {
        if (n%i == 0) {
            cnt++;
            while (n%i == 0) n /= i;
        }
    }
    cout << cnt + (n>1);
}
