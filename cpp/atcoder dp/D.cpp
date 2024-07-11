#include <iostream>
using namespace std;

int main()
{
    int n, W;
    cin >> n >> W;
    int w[n+1], v[n+1];
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    long long dp[W+1] = {};
    for (int i = 1; i <= n; i++)
        for (int j = W; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

    // for (int i = 0; i <= W; i++) cout << dp[i] << ' ';
    cout << dp[W];
}