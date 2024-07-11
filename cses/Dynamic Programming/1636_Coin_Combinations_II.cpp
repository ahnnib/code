#include <iostream>
using namespace std;

const int mod = 0x3B9ACA07;

int main()
{
    int n, x;
    cin >> n >> x;
    int c[n];
    for (int i = 0; i < n; i++) cin >> c[i];

    int dp[x+1] = {};
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int w = 0; w <= x; w++)
            if (w >= c[i]) dp[w] = (dp[w] + dp[w - c[i]]) % mod;

    cout << dp[x];
}