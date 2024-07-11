#include <iostream>
using namespace std;

const int mod = 0x3B9ACA07;

long long expo(long long a, long long b)
{
    if (b == 0) return 1;
    long long t = expo(a, b/2) % mod;
    t = t * t % mod;
    return t * (b % 2 ? a : 1) % mod;
}

int main()
{
    int n;
    cin >> n;

    int half = n * (n + 1) / 2;
    if (half % 2) return cout << 0, 0;
    half /= 2;

    // 0-1 knapsack
    int dp[half + 1] = {};
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = half; j >= i; j--)
            dp[j] = (dp[j] + dp[j - i]) % mod;

    cout << dp[half] * expo(2, mod - 2) % mod; // modular inversion
}
