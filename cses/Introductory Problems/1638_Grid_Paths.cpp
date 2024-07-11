#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char grid[n+1][n+1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> grid[i][j];

    int dp[n+1][n+1] = {};

    if (grid[1][1] != '*') dp[1][1] = 1;
    dp[0][1] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (grid[i][j] == '*') dp[i][j] = 0;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
        }
    }

    cout << dp[n][n];
}