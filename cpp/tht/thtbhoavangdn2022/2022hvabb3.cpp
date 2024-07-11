#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ll x, n, m; cin >> x >> n >> m;

    ll le = lcm(x, m) / x;
    cout << n / le;
}
