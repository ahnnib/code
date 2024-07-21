#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int n, m; struct T { int w, v; } a[40];

int main() {
    freopen("caitui.inp", "r", stdin);
    freopen("caitui.out", "w", stdout);
    cin >> n >> m; for (int i = 0; i < n; i++) cin >> a[i].w >> a[i].v;
    int dp[m+1] = {};
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= a[i].w; j--) {
            dp[j] = max(dp[j], dp[j - a[i].w] + a[i].v);
        }
    }
    cout << dp[m];
}