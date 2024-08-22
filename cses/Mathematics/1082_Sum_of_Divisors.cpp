#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

const int mod = 1e9 + 7;
const int inv = 500000004;
ll range_sum(ll a, ll b) {
    ll t = (a + b)%mod * ((b - a + 1)%mod) % mod;
    return t * inv % mod;
}
int main() {
    ll n; cin >> n;
    ll i = 1;
    ll res = 0;
    while (i <= n) {
        ll q = n/i;
        ll last = n/q;
        res += (q%mod) * range_sum(i, last) % mod;
        res %= mod;
        i = last+1;
    }
    cout << res;
}