#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll l, r;
ll dp[18][180][5130];
int w[10];
ll f(vector<int> &dig, int vt, int t1, int t2, ll t3, bool tight) {
    if (vt < 0) {
        if (__gcd(t1, t2) == 1) return t3;
        return 0;
    }
    if (tight != 1 && dp[vt][t1][t2] != -1) return dp[vt][t1][t2];
    ll res = 0;
    int lim = tight ? dig[vt] : 9;
    for (int i = 0; i <= lim; i++) {
        res += f(dig, vt - 1, t1 + i, t2 + w[i], t3 * 10 + i, tight & (dig[vt] == i));
    }
    if (!tight) dp[vt][t1][t2] = res;
    return res;
}
vector<int> get(ll x) {
    vector<int> res;
    for(; x; x /= 10) {
        res.push_back(x % 10);
        x /= 10;
    }
    return res;
}
void sol() {
    cin >> l >> r;
    // for (ll i = 0; i <= 100; i++) {
    //     vector<int> dig = get(i);
    //     cout << f(dig, dig.size()-1, 0, 0, 1) << ' ';
    // }
    vector<int> dig_l = get(l-1), dig_r = get(r);
    ll g2 = f(dig_r, dig_r.size()-1, 0, 0, 0, 1);
    ll g1 = f(dig_l, dig_l.size()-1, 0, 0, 0, 1);
    cout << g2 << ' ' << g1 << '\n';
}

int main() {
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= 9; i++) w[i] = w[i-1] + i*i;
    int t = 1;
    // cin >> t;
    while(t--) sol();
}