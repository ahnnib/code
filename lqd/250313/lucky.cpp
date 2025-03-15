#include <iostream>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    freopen("lucky.inp", "r", stdin);
    freopen("lucky.out", "w", stdout);
    ll n; cin >> n;

    ll len = 1;
    while (n > (1ll<<len)) {
        n -= 1ll<<len;
        len++;
    }

    n--;

    string bin = "";
    for (; n; n >>= 1) {
        bin = bin + char((n & 1) + 48);
    }

    // fill in leading 0s
    while (bin.size() < len) {
        bin += "0";
    }

    for (ll i = bin.size()-1; i >= 0; i--) {
        cout << (bin[i] == '1' ? 2 : 1);
    }
}