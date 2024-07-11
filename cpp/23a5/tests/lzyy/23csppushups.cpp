#include <iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("pushups.inp", "r", stdin);
    freopen("pushups.out", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    int a[m+1] = {};
    for (int i = 1; i <= m; i++)
        cin >> a[i];

    // dp knapsack
    bool dp[n+1][n+1] = {}; // dp[i][j]: khả năng chống đấy i lần được j điểm.
    dp[0][0] = 1;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (!dp[i][j]) continue;
            for (int k = 1; k <= m; k++)
            {
                if (i + j + a[k] <= n)
                    dp[i + j + a[k]][j + a[k]] |= dp[i][j];
                // chống đẩy S + a[k] lần
            }
        }
    }

    for (int i = n; i >= 0; i--)
    {
        if (dp[n][i]) return cout << i, 0;
    }
    cout << -1;
}