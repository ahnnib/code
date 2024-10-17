#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const int N = 105;
int n; ll m;
ll w[N], d[N], a[N];
ll dp[10005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("caykhe.inp", "r", stdin);
    freopen("caykhe.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> d[i] >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        for (ll k = 1; a[i] > 0; k++) {
            ll cnt = min(k, a[i]);
            a[i] -= k;
            ll gt = cnt * d[i], tl = cnt * w[i];

            for (ll s = m; s >= tl; s--)
                dp[s] = max(dp[s], dp[s - tl] + gt);
        }
    }

    ll res = -1e18;
    for (ll i = 1; i <= m; i++) res = max(res, dp[i]);

    cout << res;
}