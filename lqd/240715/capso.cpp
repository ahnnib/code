#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    freopen("capso.inp", "r", stdin);
    freopen("capso.out", "w", stdout);
    int n; cin >> n;
    map<int, ll> cnt;
    int a[n]; for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll res = 0;
    for (auto &[i, j] : cnt) {
        res += j * (j - 1) / 2;
    }
    cout << res;
}