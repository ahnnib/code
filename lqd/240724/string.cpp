#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int main() {
    freopen("string.inp", "r", stdin);
    freopen("string.out", "w", stdout);
    string s, t; cin >> s >> t;
    int ns = s.size(), nt = t.size();
    vector< vector<int> > dp(ns+1, vector<int>(nt+1, 2e9));
    dp[0][0] = 0;
    for (int i = 0; i <= ns; i++) {
        for (int j = 0; j <= nt; j++) {
            if (i) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            if (j) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            if (i && j) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (s[i-1] != t[j-1]));
        }
    }
    cout << dp[ns][nt];
}