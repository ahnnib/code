#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int q = 1; ll m;
ll mul(ll a, ll b) {
    ll res = 0;
    while (b) {
        if (b & 1) res = (res + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> q;
    cin >> m;
    while (q--) {
        ll n; cin >> n;
        ll t[3] = {n-1, n, n+1};
        for (ll &i : t) if (i%2 == 0) { i /= 2; break; }
        for (ll &i : t) if (i%3 == 0) { i /= 3; break; }
        cout << mul(mul(t[0], t[1]), t[2]) << '\n';
    }
}