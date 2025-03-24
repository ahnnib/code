#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    freopen("zeros.inp", "r", stdin);
    freopen("zeros.out", "w", stdout);
    ll a, b;
    cin >> a >> b;

    auto cnt = [&](ll p) -> int { // p^k in [a, b], k max
        int k = 0;
        ll t = p;
        while (t <= b) {
            // Compute the smallest multiple of t not less than a.
            // The formula for ceiling division is: (a + t - 1) / t.
            ll firstMultiple = (a + t - 1) / t * t;
            if (firstMultiple <= b)
                k++;
            else
                break;
            t *= p;
        }
        return k;
    };

    int exponent2 = cnt(2);
    int exponent5 = cnt(5);

    cout << min(exponent2, exponent5);
}