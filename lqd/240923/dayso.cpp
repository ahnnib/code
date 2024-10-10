#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define dbg cout << "dfad\n";

const ll mod = 1e9 + 7;
ll k, n;
ll exp(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void sol() {
    cin >> k >> n;
    if (n == 1) cout << 1;
    else if (n == 2) cout << k;
    else cout << exp(k, exp(2, n-3, mod-1), mod);
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("DAYSO.INP", "r", stdin);
    freopen("DAYSO.OUT", "w", stdout);

    int t = 1;
    cin >> t;
    while (t--) sol();
}
