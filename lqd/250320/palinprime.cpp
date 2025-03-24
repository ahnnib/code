#include <iostream>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

bool prime(int x) {
    if (x <= 3) return x > 1;
    if (x % 2 == 0 || x % 3 == 0) return 0;
    for (int i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i+2) == 0) return 0;
    }
    return 1;
}

ll f(ll x) {
    ll res = 0;
    for (ll i = 1; i <= 1000000; i++) {
        ll t = i, ii = i, ht;
        for (; ii; ii /= 10) {
            t = t * 10 + ii % 10;
        }
        ht = t;

        int sum = 0;
        for (; t; t /= 10) {
            sum += t % 10;
        }
        if (prime(sum) == true && ht <= x) res++;

        t = i; ii = i; sum = 0; ii /= 10;
        for (; ii; ii /= 10) {
            t = t * 10 + ii % 10;
        }
        ht = t;

        if (t > x) break;
        for (; t; t /= 10) {
            sum += t % 10;
        }
        if (prime(sum) == true && ht <= x) res++;

        return res;
}

int main() {
    freopen("palinprime.inp", "r", stdin);
    freopen("palinprime.out", "w", stdout);
	ll l, r; cin >> l >> r;
    cout << f(r) - f(l-1);
}