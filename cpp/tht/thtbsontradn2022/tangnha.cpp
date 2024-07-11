#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    int n; cin >> n; ll mx = 0;
    ll a[n]; for (int i = 0; i < n; i++) cin >> a[i], mx = max(mx, a[i]);

    int res = 0;
    for (int i = 0; i < n; i++) if (mx == a[i]) res++; cout << res;
}
