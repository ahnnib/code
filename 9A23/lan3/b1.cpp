#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, m, q = 1;
    cin >> n >> m;
    cin >> q;
    while (q--) {
        ll r, c; cin >> r >> c;
        string res;
        if (n % 2 == 0) {
            if (r % 2 == 0) res = "BLU";
            else res = "RED";
        } else {
            if (r % 2 == 0) res = "RED";
            else res = "BLU";
        }
        if (c % 2 == 0) {
            if (res == "BLU") res = "RED";
            else if (res == "RED") res = "BLU";
        }
        cout << res << '\n';
    }
}
