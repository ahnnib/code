#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    // dung giap cho a_i lon nhat
    ll n, k; cin >> n >> k;
    ll res = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        mx = max(mx, a);
        res += a;
    }
    cout << res - mx + max(0ll, mx - k) + 1;
}