#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int main() {
    ll n, a, b, c; cin >> n >> a >> b >> c;
    auto lcm = [](ll &a, ll &b) -> ll { return a / __gcd(a, b) * b; };
    ll l1 = lcm(a, b), l2 = lcm(b, c), l3 = lcm(a, c), l4 = lcm(l1, c);
    cout << n/a + n/b + n/c - n/l1 - n/l2 - n/l3 + n/l4;
}