#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

const ll m = 2 * (1e9 + 7);

int main() {
    int n; cin >> n; ll a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    ll sum = 0, sumsq = 0;
    for (int i = 0; i < n; i++) {
        (sum += a[i]) %= m;
        (sumsq += a[i] * a[i]) %= m;
    }
    ll Q = (sum * sum - sumsq + m * m) % m;
    cout << Q / 2;
}