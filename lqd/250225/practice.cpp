#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    freopen("practice.inp", "r", stdin);
    freopen("practice.out", "w", stdout);
    ll n, c; cin >> n >> c;
    pair<ll, ll> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n);

    int cnt = 0;
    for (int i = 0; i < n && c >= a[i].first; i++) {
        cnt++;
        c += a[i].second;
    }

    cout << cnt;
}