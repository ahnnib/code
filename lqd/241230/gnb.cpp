#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    freopen("gnb.inp", "r", stdin);
    freopen("gnb.out", "w", stdout);
    ll n; cin >> n;
    ll a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    /*
    a[i] + a[j] = a[u] - a[k]
    i <= j <= k < u
    */
    unordered_map<ll, bool> mark, ok;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i <= k; i++) {
            mark[a[i] + a[k]] = true;
        }
        for (int u = k+1; u < n; u++) {
            if (mark[a[u] - a[k]]) {
                ok[a[u]] = true;
            }
        }
    }
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += ok[a[i]];
    }
    cout << cnt;
}