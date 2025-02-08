#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    freopen("hp.inp", "r", stdin);
    freopen("hp.out", "w", stdout);
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll sum = 0, res = 0;
    for (int i = 1; i < n; i++) {
        sum += a[i-1];
        res = res + sum * a[i];
    }

    cout << res;
}