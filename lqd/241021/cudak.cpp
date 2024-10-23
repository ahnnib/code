#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll a, b, k;
ll dp[20][180];

ll f(vector<int> &dig, int vt, bool tight, int t) {
    if (vt < 0) {
        return t == k;
    }

    if (tight != 1 && dp[vt][t] != -1) {
        return dp[vt][t];
    }

    ll res = 0; int lim = tight ? dig[vt] : 9;

    for (int d = 0; d <= lim; d++) {
        bool newTight = dig[vt] == d ? tight : 0;
        res += f(dig, vt-1, newTight, t + d);
    }

    if (tight != 1) {
        dp[vt][t] = res;
    }

    return res;
}
vector<int> get_dig(ll x) {

    vector<int> res;
    while (x) {
        res.push_back(x % 10);
        x /= 10;
    }
    return res;
}
ll get_range(ll &a, ll &b) {
    vector<int> dig_a = get_dig(a-1);
    vector<int> dig_b = get_dig(b);

    ll g2 = f(dig_b, dig_b.size()-1, 1, 0);
    ll g1 = f(dig_a, dig_a.size()-1, 1, 0);

    return g2 - g1;
}

int main() {
    freopen("cudak.inp", "r", stdin);
    freopen("cudak.out", "w", stdout);

    memset(dp, -1, sizeof dp);

    cin >> a >> b >> k;

    cout << get_range(a, b) << '\n';

    ll l = a, r = b, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (get_range(l, mid) > 0) r = mid - 1;
        else l = mid + 1;
    }
    cout << l;
}