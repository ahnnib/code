#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int main() {
    ll x; cin >> x;
    if (x & 1) {
        cout << -1;
        return 0;
    }
    ll C = x / 2;
    if (C & 1) cout << C / 2 << ' ' << C / 2 + 1;
    else cout << C / 2 << ' ' << C / 2;
}
