#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    ll n; cin >> n;
    ll cnt = 2; for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) cnt += 2 - (i == n / i);
    }
    cout << (cnt >> 1);
}
