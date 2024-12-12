#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll n;
set<ll> res;

void f(ll n) {
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ll j = n / i;
            res.insert((i - 1) * (j + 1));
            f((i - 1) * (j + 1));
        }
    }
}

int main() {
    freopen("woday.inp", "r", stdin);
    freopen("woday.out", "w", stdout);
    cin >> n;
    f(n);
    cout << res.size() << '\n';
    for (ll i : res) cout << i << ' ';
}