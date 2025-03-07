#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int a, b;
int dp[8][2000];
const int C = 1000;

int f(vector<int> &dig, int vt, int tt, bool tight) {
    if (vt < 0) {
        return tt + C == 1 + C;
    }

    if (!tight && dp[vt][tt + C] != -1) {
        return dp[vt][tt + C];
    }

    int res = 0, lim = tight ? dig[vt] : 9;
    for (int d = 0; d <= lim; d++) {
        res += f(dig, vt - 1, tt + (vt & 1 ? d : -d), tight & (dig[vt] == d));
    }

    if (!tight) {
        dp[vt][tt + C] = res;
    }

    return res;
}

int main() {
    freopen("raone.inp", "r", stdin);
    freopen("raone.out", "w", stdout);

    memset(dp, -1, sizeof dp);

    int t = 1;
    // cin >> t;
    while (t--) {

        cin >> a >> b;

        auto get_dig = [](int x) {
            vector<int> res;
            while (x) {
                res.push_back(x % 10);
                x /= 10;
            }
            return res;
        };

        vector<int> dig_a = get_dig(a-1), dig_b = get_dig(b);

        int g2 = f(dig_b, dig_b.size()-1, 0, 1);
        int g1 = f(dig_a, dig_a.size()-1, 0, 1);

        cout << g2 - g1;
    }
}