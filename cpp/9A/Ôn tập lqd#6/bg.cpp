#include <iostream>

#define int long long

const int mod = 1e9 + 7;
int pow(int a, int b)
{
    if (b == 0) return 1;
    if (b == 1) return a;
    int tmp = pow(a, b/2) % mod;
    tmp = tmp * tmp % mod;
    if (b % 2) return tmp * a;
    return tmp;
}

signed main()
{
    freopen("bg.inp", "r", stdin);
    freopen("bg.out", "w", stdout);

    int a, b, n;
    std::cin >> a >> b >> n;

    int t = pow(2, n-1);

    // std::cout << t << '\n';
    int A = ((t - 1) * b) % mod;
    int B = ((t - 2) * a) % mod;
    std::cout << (A + mod - B) % mod;
}
