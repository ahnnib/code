#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1000'000'000;

int main()
{
    ll l, r; cin >> l >> r;

    ll sz = log2(r / l);

    ll t1 = r / pow(2, sz) - l + 1;
    ll t2 = max(0ll, (ll)(r / (3 * pow(2, sz-1)) - l + 1));

    ll ans = (t1 + t2 * sz) % mod;

    cout << sz + 1 << ' ' << ans << '\n';
}