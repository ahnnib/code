#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    freopen("midpoint.inp", "r", stdin);
    freopen("midpoint.out", "w", stdout);

    int t = 1;
    cin >> t;
    while (t--) {
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        ll t1 = x1 + x2, t2 = y1 + y2;
        cout << t1 / 2 << (t1 & 1 ? ".5" : "") << ' ';
        cout << t2 / 2 << (t2 & 1 ? ".5" : "") << '\n';
    }
}

