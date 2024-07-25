#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int main() {
    freopen("nkpalin.inp", "r", stdin);
    freopen("nkpalin.out", "w", stdout);
    string s; cin >> s;
    string t = s; reverse(t.begin(), t.end());
    int nd = s.size();
    s = ' ' + s; t = ' ' + t;
    int dp[nd+1][nd+1] = {};
    for (int i = 1; i <= nd; i++) {
        for (int j = 1; j <= nd; j++) {
            if (s[i] == t[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int x = nd, y = nd; string res;
    while (x > 0 && y > 0) {
        if (s[x] == t[y]) res += s[x], x--, y--;
        else if (dp[x-1][y] >= dp[x][y-1]) x--;
        else y--;
    }
    cout << res;
}