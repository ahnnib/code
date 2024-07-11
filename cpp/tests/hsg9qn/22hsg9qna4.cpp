#include <iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("market.inp", "r", stdin);
    freopen("market.out", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    int w[n+1], v[n+1];
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    long long dp[m+1] = {};
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    if (dp[m] != 0) cout << dp[m];
    else cout << -1;
    // for (int i = 1; i <= m; i++) cout << dp[i] << ' ';
}
/*
3 8
3 30
4 50
5 60
30 50 90
*/