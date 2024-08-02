#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int main() {
    int n, k; cin >> n >> k;
    int a[k]; for (int i = 0; i < k; i++) cin >> a[i];
    vector<int> dp(n+1, 1e9);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (a[j] <= i && dp[i - a[j]] != 1e9) dp[i] = min(dp[i], dp[i - a[j]] + 1);
        }
    }
    if (dp[n] == 1e9) cout << -1;
    else cout << dp[n];
}