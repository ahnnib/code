#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    freopen("bai2.inp", "r", stdin);
    freopen("bai2.out", "w", stdout);
    int n; cin >> n;
    ll a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        ll sum = 0, G = 0, L = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];

            G = __gcd(G, a[j]);

            if (i == j) L = a[j];
            else L = L * a[j] / __gcd(L, a[j]);

            if (sum % L == 0) cnt++;


            if (L > 600000) break;
        }
    }
    cout << cnt;
}