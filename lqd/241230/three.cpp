#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    freopen("three.inp", "r", stdin);
    freopen("three.out", "w", stdout);
    ll n, k; cin >> n >> k;
    ll a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    map<ll, ll> mp1, mp2;
    ll cnt = 0;
    for (int i = n-1; i >= 0; i--) {
        mp2[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        mp2[a[i]]--;
        if (a[i] % k == 0) cnt += mp1[a[i] / k] * mp2[a[i] * k];
        mp1[a[i]]++;
    }

    cout << cnt;
}