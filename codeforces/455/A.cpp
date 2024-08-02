#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

ll dp[100001]; int cnt[100001];

int main() {
    int n; cin >> n; int a[n]; for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    dp[1] = cnt[1];
    // dp[i]: max sum if we consider all numbers 1 -> i, ignoring numbers > i
    // case 1: use i -> dp[i-2] + i * cnt[i];
    // case 2: not use i -> dp[i] = dp[i-1]
    for (int i = 2; i <= 100000; i++) {
        dp[i] = max(dp[i-1], 1ll * i * cnt[i] + dp[i-2]);
    }
    cout << dp[100000];
}