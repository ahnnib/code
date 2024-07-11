#include <iostream>
using namespace std;

int main()
{
    int n, x;
    cin >> x >> n;
    int c[n+1];
    for (int i = 1; i <= n; i++) cin >> c[i];

    long long dp[x+1] = {};
    for (int i = 1; i <= x; i++) dp[i] = 2147483647;
    // knapsack DP
    for (int i = 1; i <= n; i++)
        for (int w = 0; w <= x; w++)
            if (w >= c[i])
                dp[w] = min(dp[w], dp[w - c[i]] + 1);

    cout << (dp[x] == 2147483647 ? -1 : dp[x]);
}