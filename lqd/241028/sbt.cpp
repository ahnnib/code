#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll l, r;
ll dp[18][9 * 18 + 1][81 * 18 + 1];
ll f(vector<int> &dig, int vt, int t1, int t2, bool tight) {
    if (vt < 0) {
        return __gcd(t1, t2) == 1;
    }

    if (!tight && dp[vt][t1][t2] != -1) {
        return dp[vt][t1][t2];
    }

    ll res = 0; int lim = tight ? dig[vt] : 9;
    for (int d = 0; d <= lim; d++) {
        res += f(dig, vt - 1, t1 + d, t2 + d*d, tight & (dig[vt] == d));
    }

    if (!tight) {
        dp[vt][t1][t2] = res;
    }

    return res;
}

int main() {
    // freopen("sbt.inp", "r", stdin);
    // freopen("sbt.out", "w", stdout);

    cin >> l >> r;

    auto get_dig = [](int x) {
        vector<int> res;
        while (x) {
            res.push_back(x % 10);
            x /= 10;
        }
        return res;
    };

    vector<int> dig_l = get_dig(l-1), dig_r = get_dig(r);

    memset(dp, -1, sizeof dp);
    ll g2 = f(dig_r, dig_r.size()-1, 0, 0, 1);
    ll g1 = f(dig_l, dig_l.size()-1, 0, 0, 1);

    cout << g2 - g1;
}