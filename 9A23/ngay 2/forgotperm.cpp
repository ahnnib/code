#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
//    freopen("forgotperm.inp", "r", stdin);
//    freopen("forgotperm.out", "w", stdout);

    int t = 1;
//     cin >> t;
    while (t--) {
        ll n, s; cin >> n >> s;
        int sum = 0;
        for (int i = 0; i < n; i++) { int x; cin >> x; sum += x; }
        ll t = s + sum;
        ll l = 1, r = 1e9, mid;
        while (l <= r) {
              mid = (l + r) >> 1;
              if (mid * (mid + 1) < (t<<1)) l = mid + 1;
              else r = mid - 1;
        }
//        cout << l;
        if (l * (l + 1) == (t<<1)) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
}
