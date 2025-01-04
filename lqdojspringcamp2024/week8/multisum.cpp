#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const ll mod = 1e9 + 7;
string k; int D;
ll dp[10000][100];
ll f(int vt, int sum, bool tight) {
    if (vt == k.size()) {
        return sum == 0;
    }
    if (!tight && dp[vt][sum] != -1) return dp[vt][sum];
    int lim = tight ? k[vt] : 9;
    ll res = 0;
    for (int d = 0; d <= lim; d++) {
        res += f(vt + 1, (sum + d) % D, tight && (k[vt] == d));
        res %= mod;
    }
    if (!tight) dp[vt][sum] = res;
    return res;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> k >> D;
    for (char &i : k) i -= '0';
    cout << f(0, 0, 1) - 1; // 0 % d = 0
}