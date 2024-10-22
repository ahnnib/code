#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll a, b, k;
const int N = 180;
bool com[N];
ll dp[12][180][5000];

ll f(vector<int> &dig, int vt, bool tight, ll t1, ll t2) {
    if (vt < 0) {
        if (!com[t1] && t2 == 0) {
            return 1;
        }
        return 0;
    }

    if (dp[vt][t1][t2] != -1 && tight != 1) {
        return dp[vt][t1][t2];
    }

    ll res = 0; int lim = tight ? dig[vt] : 9;

    for (int d = 0; d <= lim; d++) {

        bool newTight = dig[vt] == d ? tight : 0;
        res += f(dig, vt-1, newTight, t1 + d, (t2 * 10 + d) % k);
    }

    if (tight != 1) dp[vt][t1][t2] = res;

    return res;
}

int main() {
    com[0] = com[1] = 1;
    int sqr = sqrt(N); for (int i = 2; i <= sqr; i++) if (!com[i])
        for (int j = i*i; j < N; j += i) com[j] = 1;

    memset(dp, -1, sizeof dp);

    freopen("tntchk.inp", "r", stdin);
    freopen("tntchk.out", "w", stdout);

    cin >> a >> b >> k;

    vector<int> dig_a, dig_b;
    a -= 1; while (a) dig_a.push_back(a % 10), a /= 10;
    while (b) dig_b.push_back(b % 10), b /= 10;

    ll g2 = f(dig_b, dig_b.size()-1, 1, 0, 0);
    ll g1 = f(dig_a, dig_a.size()-1, 1, 0, 0);

    cout << g2 - g1;
}