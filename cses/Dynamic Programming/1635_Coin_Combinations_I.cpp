#include <iostream>
using namespace std;

const int mod = 1e9 + 7;
int main()
{
    int n, x;
    cin >> n >> x;
    int c[n];
    for (int i = 0; i < n; i++) cin >> c[i];

    long long dp[x+1] = {};
    dp[0] = 1;
    // knapsack DP
    for (int w = 1; w <= x; w++)
        for (int j = 0; j < n; j++)
            if (w >= c[j]) dp[w] = (dp[w] + dp[w - c[j]]) % mod;

    cout << dp[x];
}
