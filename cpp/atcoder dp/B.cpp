#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int h[n+1] = {};
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    vector<int> dp(n+1, 2147483647); // dp[i]: chi phi toi thieu nhay toi h[i]
    dp[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k && j < i; j++)
        {
            dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
        }
    }

    cout << dp[n];
}
/*
dp[i] tạo được từ dp[i-1] ... dp[i-k]
để đến hòn đá dp[i] có thể đến từ hòn đá i-j
(1 <= j <= k, i - j >= 1)
(1 <= j <= k, i >= j)
*/