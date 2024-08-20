#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int main() {
    ll n; cin >> n;
    ll res = n;
    for (ll i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            while (n%i == 0) n /= i;
            res -= res / i;
        }
    }
    if (n > 1) res -= res / n;
    cout << res;
}