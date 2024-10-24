// 2 chữ số cạnh nhau không được cùng tính chẵn lẻ
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int a, b;
ll dp[10][2][2];

ll f(vector<int> &dig, int vt, bool tight, int tt, bool lz) {
    if (vt < 0) {
        return 1;
    }

    if (dp[vt][tt][lz] != -1 && tight != 1) {
        return dp[vt][tt][lz];
    }

    ll res = 0;
    int lim = tight ? dig[vt] : 9;
    for (int d = 0; d <= lim; d++) {
        bool newTight = d == dig[vt] ? tight : 0;
        if (lz == 1) {
            if (d == 0) {
                res += f(dig, vt - 1, newTight, 0, 1);
            }
            else {
                res += f(dig, vt - 1, newTight, d % 2, 0);
            }
        }
        else if (d % 2 != tt) {
            res += f(dig, vt - 1, newTight, d % 2, 0);
        }
    }

    if (tight != 1) {
        dp[vt][tt][lz] = res;
    }

    return res;
}

int main() {
    cin >> a >> b;

    memset(dp, -1, sizeof dp);

    auto get_dig = [&](int x) {
        vector<int> dig;
        while (x) {
            dig.push_back(x % 10);
            x /= 10;
        }
        return dig;
    };

    vector<int> dig_a = get_dig(a-1), dig_b = get_dig(b);

    ll g2 = f(dig_b, dig_b.size()-1, 1, 0, 1);
    ll g1 = f(dig_a, dig_a.size()-1, 1, 0, 1);

    cout << g2 - g1;
}