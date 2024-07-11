#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

ll sumdiv(ll x) {
    ll sum = 0;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) sum += i + (i != x/i ? x/i : 0);
    }
    return sum;
}

int main() {
    freopen("SOTT.INP", "r", stdin);
    freopen("SOTT.OUT", "w", stdout);

    ll a, b; cin >> a >> b;

    ll n1 = sumdiv(a), d1 = a;
    ll n2 = sumdiv(b), d2 = b;
    ll t1 = __gcd(n1, d1); ll t2 = __gcd(n2, d2);
    n1 /= t1; d1 /= t1;
    n2 /= t2; d2 /= t2;
    if (n1 == n2 && d1 == d2) cout << n1 << '\n' << d1;
    else cout << -1;
}
