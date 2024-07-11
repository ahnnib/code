#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    ll n, a, b; cin >> n >> a >> b;
    if (n % __gcd(a, b) != 0) {
        cout << -1;
        return 0;
    }

    if (a < b) swap(a, b);
    /* K * a + P * b = n (a >= b)
    K = (n - P * b) / a
    19 3 5
    19 5 3
    5K + 3P = 19
    (K, P) = (2, 3)

    */
    ll lim = n / b;
    for (ll P = 0; P <= lim; P++) {
        ll K = (n - P * b) / a;
        if ((n - P * b) % a == 0) {
            cout << P + K;
            return 0;
        }
    }
}

