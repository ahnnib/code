#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const int mod = 1e9 + 7;
string n; vector<int> dig;
ll dp[10001][3];

ll f(int vt, int tt, bool tight) {
    if (vt < 0) {
        return tt == 0;
    }

    if (tight != 1 && dp[vt][tt] != -1) {
        return dp[vt][tt];
    }

    ll res = 0; int lim = tight ? dig[vt] : 9;
    for (int d = 0; d <= lim; d++) {
        res += f(vt - 1, (tt + d*d) % 3, tight & (dig[vt] == d)) % mod;
        res %= mod;
    }

    if (tight != 1) {
        dp[vt][tt] = res;
    }

    return res;
}

int main() {
    freopen("tbpb3.inp", "r", stdin);
    freopen("tbpb3.out", "w", stdout);

    cin >> n;

    int tmp = n.size()-1;
    while (n[tmp] == '0') {
        n[tmp--] = '9';
    }
    n[tmp]--;

    while (!n.empty()) {
        dig.push_back(n.back() - 48);
        n.pop_back();
    }

    memset(dp, -1, sizeof dp);

    cout << f(dig.size()-1, 0, 1);
}