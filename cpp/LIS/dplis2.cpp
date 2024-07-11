#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

const int mod = 20071008;

signed main()
{
    int n; cin >> n; vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp(n); dp.assign(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = i-1; j >= 0; j--) {
            if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    for (int i : dp) cout << i << ' '; cout << '\n';
    vector<int> cnt(n); cnt.assign(n, 1);
    // for (int i = 0; i < n; i++) if (dp[i] == 1) cnt[i] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i-1; j >= 0; j--) {
            if (a[j] < a[i]) (cnt[i] += dp[j]) %= mod;
        }
    }
    // cout << cnt[n-1];
    for (int i : cnt) cout << i << ' ';
}
/*
6
1 4 3 2 2 5
1 2 2 2 2 3
*/