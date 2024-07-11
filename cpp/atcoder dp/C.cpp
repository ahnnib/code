#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int A[n+1], B[n+1], C[n+1];
    for (int i = 1; i <= n; i++)
        cin >> A[i] >> B[i] >> C[i];

    int dp[n+1][3] = {};
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = max(dp[i-1][1] + A[i], dp[i-1][2] + A[i]);
        dp[i][1] = max(dp[i-1][0] + B[i], dp[i-1][2] + B[i]);
        dp[i][2] = max(dp[i-1][1] + C[i], dp[i-1][0] + C[i]);
    }

    cout << max(dp[n][0], max(dp[n][1], dp[n][2]));
}