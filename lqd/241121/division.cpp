#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll m, n, k;
ll dp[31][31][500];
ll f(ll vt, ll t1, ll t2) {
    if (vt == 0) {
        return t1 == m && t2 == 0;
    }
    if (dp[vt][t1][t2] != -1) {
        return dp[vt][t1][t2];
    }
    ll res = 0;
    if (t1 < m) {
        res += f(vt - 1, t1 + 1, (t2 + (1ll << vt - 1)) % k);
    }
    res += f(vt - 1, t1, t2);

    return dp[vt][t1][t2] = res;
}

int main() {
    freopen("division.inp", "r", stdin);
    freopen("division.out", "w", stdout);
    memset(dp, -1, sizeof dp);
    cin >> m >> n >> k;
    cout << f(m + n - 1, 1, 1ll << (m + n - 1) % k);
}