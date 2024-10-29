#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const ll mod = 1e9 + 7;
string l, r;
ll dp[100000];
int f(string &dig, int vt, bool t1, bool t2, bool tight) {
    if (vt < 0) {
        return t1 & t2;
    }

    if (!tight && dp[vt][] != -1) {
        return dp[vt][];
    }

    int res = 0; ll lim = tight ? dig[vt] : 9;
    for (ll d = 1; d <= lim; d++) {

    }
}

int main() {
    // freopen("xenke.inp", "r", stdin);
    // freopen("xenke.out", "w", stdout);

    cin >> l >> r;

    reverse(l.begin(), l.end());
    reverse(r.begin(), r.end());

    for (int i = 0; i < l.size(); i++) l[i] -= '0';
    for (int i = 0; i < r.size(); i++) r[i] -= '0';

    ll g2 =
}