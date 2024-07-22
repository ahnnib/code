#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int main() {
    freopen("liq.inp", "r", stdin);
    freopen("liq.out", "w", stdout);
    int n; cin >> n; int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int dp[n] = {}; for (int i = 0; i < n; i++) dp[i] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << *max_element(dp, dp + n);
}