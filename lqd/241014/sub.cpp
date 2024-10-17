#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int n; ll a[100000];

void sol() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll res1 = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > 0) res1 += a[i];
    }

    if (res1 == 0) res1 = *max_element(a, a + n);

    cout << res1 << ' ';

    ll max_here = 0, max_all = -1e18;

    for (int i = 0; i < n; i++) {
        max_here = max(a[i], max_here + a[i]);
        max_all = max(max_all, max_here);
    }

    cout << max_all << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("sub.inp", "r", stdin);
    freopen("sub.out", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) sol();
}