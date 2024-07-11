#include <iostream>

#define int long long

signed main()
{
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) std::cin >> a[i];

    const int mod = 1e9+7;

    int ans = 0, sum = 0;
    for (int i = n-1; i >= 0; i--)
    {
        ans = (ans % mod + (a[i] * sum) % mod) % mod;
        sum += a[i];
    }

    std::cout << ans;
}