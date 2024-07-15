#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    freopen("vatsua.inp", "r", stdin);
    freopen("vatsua.out", "w", stdout);
    int n; cin >> n; int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += max(0, a[i] - i);
    }
    cout << res;
}