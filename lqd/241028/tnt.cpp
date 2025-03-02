#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int a, b;
int dp[9][73];

int f(vector<int> dig, int vt, int tt, bool tight) {
    if (vt < 0) {
        return (!((tt % 2 == 0) || (tt % 3 == 0) || (tt % 5 == 0) || (tt % 7 == 0)) || \
                (tt == 2 || tt == 3 || tt == 5 || tt == 7)) && tt != 1;
    }

    if (tight != 1 && dp[vt][tt] != -1) {
        return dp[vt][tt];
    }

    int res = 0, lim = tight ? dig[vt] : 9;
    for (int d = 0; d <= lim; d++) {
        res += f(dig, vt - 1, tt + d, tight & (dig[vt] == d));
    }

    if (tight != 1) {
        dp[vt][tt] = res;
    }

    return res;
}

int main() {
    freopen("tnt.inp", "r", stdin);
    freopen("tnt.out", "w", stdout);

    cin >> a >> b;

    auto get_dig = [&](int x) {
        vector<int> res;
        while (x) {
            res.push_back(x % 10);
            x /= 10;
        }
        return res;
    };


    vector<int> dig_a = get_dig(a - 1), dig_b = get_dig(b);

    memset(dp, -1, sizeof dp);
    int g2 = f(dig_b, dig_b.size()-1, 0, 1);
    int g1 = f(dig_a, dig_a.size()-1, 0, 1);

    cout << g2 - g1;
}