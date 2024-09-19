#include <iostream>
using namespace std;
#define ll long long

const ll mod = 1e9 + 7;
ll exp(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll a, b, c;
    int n; cin >> n; while (n--) {
        cin >> a >> b >> c;
        cout << exp(a, exp(b, c, mod-1), mod) << '\n';
    }
}
/*
Fermat's little theorem: a^(p-1) = 1 (mod p prime)
let d = b^c = (p-1)k + r -> d = r (mod p-1)
-> a^d = a^r (mod p)
*/