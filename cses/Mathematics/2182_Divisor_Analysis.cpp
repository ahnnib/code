// https://usaco.guide/problems/cses-2182-divisor-analysis/solution
#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

const ll m = 1e9 + 7;
ll exp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll g(ll x, ll n) {
    if (n == 1) return x;
    if (n & 1) return x * (1 + g(x, n-1)) % m;
    ll t = g(x, n>>1) % m;
    return (t + exp(x, n>>1) * t) % m;
}
int main() {
    int n; cin >> n; ll num = 1;
    ll cnt = 1, sum = 1, cnt2 = 1, pro = 1;
    for (int i = 0; i < n; i++) {
        ll x, k; cin >> x >> k;
        cnt = cnt * (k + 1) % m;
        sum = sum * (1 + g(x, k)) % m;
        num = num * exp(x, k) % m;
        pro = exp(pro, k+1) * exp(exp(x, k*(k+1)>>1), cnt2) % m;
        cnt2 = cnt2 * (k+1) % (m-1); // a^b = a^(b % (p-1)) modulo p
    }
    cout << cnt << ' ' << sum << ' ' << pro;
}