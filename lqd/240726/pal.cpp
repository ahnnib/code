#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";
const ll mod = 1e9 + 7;
string s; ll f[205][205];
int main() {
    freopen("pal.inp", "r", stdin);
    freopen("pal.out", "w", stdout);
    cin >> s; int n = s.size();
    for (int i = 0; i < n; i++) f[i][i] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) f[i][j] = (f[i+1][j] % mod + (f[i][j-1] % mod) + 1) % mod;
            else f[i][j] = (f[i+1][j] + (f[i][j-1] % mod) - f[i+1][j-1] + mod) % mod;
        }
    }
    cout << f[0][n-1];
}