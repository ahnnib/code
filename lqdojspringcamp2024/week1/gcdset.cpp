#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

void solve() {
    int n; ll k; cin >> n >> k;
    ll a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    // gcd(a, b) = k => gcd(a/k, b/k) = 1
    ll t = 0;
    for (int i = 0; i < n; i++) if (a[i] % k == 0) t = __gcd(t, a[i] / k);
    if (t == 1) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}