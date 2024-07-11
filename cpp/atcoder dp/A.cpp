#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int h[n+1] = {};
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    int dp[n+1] = {}; // dp[i]: chi phi toi thieu nhay toi h[i]
    dp[2] = abs(h[1] - h[2]);

    for (int i = 3; i <= n; i++)
    {
        dp[i] = min(dp[i-2] + abs(h[i] - h[i-2]), dp[i-1] + abs(h[i-1] - h[i]));
    }

    cout<<dp[n];
}