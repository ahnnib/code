#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll a, b; int k;

vector<int> dig;
ll dp[18][162];
ll f(int vt, int tt, bool tight) {
    if (vt < 0) return tt == k;
    if (!tight && dp[vt][tt] != -1) return dp[vt][tt];
    ll res = 0; int lim = tight ? dig[vt] : 9;
    for (int d = 0; d <= lim; d++) {
        res += f(vt - 1, tt + d, tight && (dig[vt] == d));
    }
    if (!tight) dp[vt][tt] = res;
    return res;
}

ll sol(ll x) {
    dig.clear();
    for (; x; x /= 10) dig.push_back(x % 10);
    return f(dig.size()-1, 0, 1);
}

int main() {
    memset(dp, -1, sizeof dp);

    cin >> a >> b >> k;

    ll g2 = sol(b), g1 = sol(a-1);
    cout << g2 - g1 << '\n';

    if (g2 == g1) {
        cout << -1;
    }
    else {
        ll l = a, r = b, mid;
        while (l <= r) {
            mid = l + r >> 1;
            if (sol(mid) - g1 > 0) r = mid - 1;
            else l = mid + 1;
        }
        cout << l;
    }
}