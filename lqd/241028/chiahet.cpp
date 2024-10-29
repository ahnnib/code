#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int a, b, k;
int dp[31][10000][63]; // ((2147399999, 62)
/*
t2 chia het cho k
-> t2 >= k
neu k > t2 -> khong co so thoa
*/
int f(vector<int> &dig, int vt, int t1 /*so*/, int t2 /*tong chu so*/, bool tight) {
    if (vt < 0) {
        return t1 == 0 && t2 == 0;
    }

    if (!tight && dp[vt][t1][t2] != -1) {
        return dp[vt][t1][t2];
    }

    int res = 0, lim = tight ? dig[vt] : 9;
    for (int d = 0; d <= lim; d++) {
        res += f(dig, vt - 1, (t1 * 10 + d) % k, (t2 + d) % k, tight & (dig[vt] == d));
    }

    if (!tight) {
        dp[vt][t1][t2] = res;
    }

    return res;
}

int main() {
    freopen("chiahet.inp", "r", stdin);
    freopen("chiahet.out", "w", stdout);

    cin >> a >> b >> k;

    auto get_dig = [](int x) {
        vector<int> res;
        while (x) {
            res.push_back(x % 10);
            x /= 10;
        }
        return res;
    };

    vector<int> dig_a = get_dig(a-1), dig_b = get_dig(b);

    memset(dp, -1, sizeof dp);
    int g2 = f(dig_b, dig_b.size()-1, 0, 0, 1);
    int g1 = f(dig_a, dig_a.size()-1, 0, 0, 1);

    cout << g2 - g1;
}