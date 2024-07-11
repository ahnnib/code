#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x[n+1];
    for (int i = 1; i <= n; i++) cin >> x[i];

    int MAX = 1000 * n;

    int dp[n+1][MAX+1] = {};
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= MAX; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (j - x[i] >= 0 && dp[i-1][j - x[i]]) dp[i][j] = 1;
        }
    }

    vector<int> ans; // possible

    for (int i = 1; i <= MAX; i++)
    {
        if (dp[n][i]) ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << ' ';
}