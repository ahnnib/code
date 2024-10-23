#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll l, r; vector<int> dig_l, dig_r;
ll dp[20][1040];

ll f(vector<int> &dig, int vt, bool tight, ll tt, bool lz) {

    if (vt < 0) {
        if (lz == 1) return 0;
        return 1;
    }

    if (dp[vt][tt] != -1 && tight != 1) {
        return dp[vt][tt];
    }

    int lim = tight ? dig[vt] : 9;
    ll res = 0;
    for (int d = 0; d <= lim; d++) {

        bool newTight = dig[vt] == d ? tight : 0;

        if (d == 0) {
            if (lz == 1) {
                res += f(dig, vt - 1, newTight, tt, 1);
            }
            else if (!(tt & 1)) {
                res += f(dig, vt - 1, newTight, tt + 1, 0);
            }
        }
        else if (!((tt >> d) & 1)) res += f(dig, vt - 1, newTight, tt + (1 << d), 0);
    }

    if (tight != 1) dp[vt][tt] = res;

    return res;
}

int main() {
    // freopen("cspb.inp", "r", stdin);
    // freopen("cspb.out", "w", stdout);

    memset(dp, -1, sizeof dp);

    cin >> l >> r;

    l -= 1;
    while (l) dig_l.push_back(l % 10), l /= 10;
    while (r) dig_r.push_back(r % 10), r /= 10;

    ll g2 = f(dig_r, dig_r.size()-1, 1, 0, 1);
    ll g1 = f(dig_l, dig_l.size()-1, 1, 0, 1);

    cout << g2 - g1;
}