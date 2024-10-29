#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll a, b;
ll dp[18][9 * 18 + 1];
ll f(vector<int> &dig, int vt, ll tt, bool tight) {
    if (vt < 0) {
        return tt;
    }

    if (!tight && dp[vt][tt] != -1) return dp[vt][tt];

    ll res = 0; int lim = tight ? dig[vt] : 9;
    for (int d = 0; d <= lim; d++) {
        res += f(dig, vt - 1, tt + d, tight & (dig[vt] == d));
    }

    if (!tight) dp[vt][tt] = res;

    return res;
}

int main() {
    freopen("tongcs.inp", "r", stdin);
    freopen("tongcs.out", "w", stdout);

    memset(dp, -1, sizeof dp);

    cin >> a >> b;

    auto get_dig = [](ll x) {
        vector<int> res;
        while (x) {
            res.push_back(x % 10);
            x /= 10;
        }
        return res;
    };

    vector<int> dig_a = get_dig(a-1), dig_b = get_dig(b);

    ll g2 = f(dig_b, dig_b.size()-1, 0, 1);
    ll g1 = f(dig_a, dig_a.size()-1, 0, 1);

    cout << g2 - g1;
}