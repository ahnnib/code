#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    // freopen("tile.inp", "r", stdin);
    // freopen("tile.out", "w", stdout);
    int n; cin >> n; int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    ll h = 1;
    for (int i = 0; i < n; i++) {
        if (i > h) break;
        h = max(h, (ll)i + a[i]);
    }
    cout << h;
}