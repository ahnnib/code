#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

bool f[1005][1005]; int dp[1005];
int main() {
    freopen("countpl.inp", "r", stdin);
    freopen("countpl.out", "w", stdout);
    string s; cin >> s; int n = s.size(); s = ' ' + s;
    // f[i][j]: xau s[i..j] co phai la xau doi xung
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--) {
            if (i == j || (i == j+1 && s[i] == s[j])) f[i][j] = 1;
            else if (s[i] == s[j]) f[i][j] = f[i-1][j+1];
            else f[i][j] = 0;
        }
    }
    for (int i = 0; i <= n; i++) dp[i] = i;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (f[i][j]) dp[i] = min(dp[i], dp[j-1] + 1);
        }
    }
    cout << dp[n];
}