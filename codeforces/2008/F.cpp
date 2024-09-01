#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

const int N = 2e5 + 1;
const ll mod = 1e9 + 7;
ll a[N];

ll mul(ll a, ll b) {
    ll res = 0;
    while (b) {
        if (b & 1) res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}
ll exp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
void solve() {
    ll n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll s = 0, P = 0;
    for (int i = n; i >= 1; i--) {
        P += a[i] * s % mod;
        P %= mod;
        s = (s + a[i]) % mod;
    }
    ll Q = n * (n - 1) / 2;
    cout << P * exp(Q, mod-2) % mod << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}