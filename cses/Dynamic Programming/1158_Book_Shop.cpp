#include <iostream>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int h[n], s[n];
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) cin >> s[i];

    int dp[x+1] = {};
    for (int i = 1; i <= n; i++)
        for (int j = x; j >= h[i]; j--)
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);

    cout << dp[x];
}
/*
4 10
4 8 5 3
5 12 8 1

*/