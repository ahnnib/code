#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

string n; int K;
const ll mod = 1e9;
ll dp[301][2700];
ll f(int pos, int sum, bool tight) {
    if (pos == n.size()) {
        return sum == K;
    }
    if (!tight && dp[pos][sum] != -1) return dp[pos][sum];
    int lim = tight ? n[pos] : 9; ll res = 0;
    for (int d = 0; d <= lim; d++) {
        res += f(pos + 1, sum + d, tight && (n[pos] == d));
        res %= mod;
    }
    if (!tight) dp[pos][sum] = res;
    return res;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (char &i : n) {
        K += i -= '0';
    }
    cout << f(0, 0, 1);
}