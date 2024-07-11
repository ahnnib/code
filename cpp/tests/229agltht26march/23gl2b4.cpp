#include <iostream>

const int mod = 1e9;

long long mu(long long a, long long x)
{
    long long t = 1;
    while (x)
    {
        if (x % 2) t = t * a % mod;
        a = a * a % mod;
        x /= 2;
    }
    return t;
}

signed main()
{

    // freopen("MUL.inp", "r", stdin);
    // freopen("MUL.out", "w", stdout);

    int n;
    std::cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < n; i++) std::cin >> b[i];

    int res = 0;
    for (int i = 0; i < n; i++)
        res = (res + mu(a[i], b[i])) % mod;

    std::cout << res;
}