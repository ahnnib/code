#include <iostream>
#include <cstring>
#include <algorithm>

const int N = 19;
long long dp[N][10][2][2]; // [len][lead digit][lead_zero][tight]

long long f(std::string &digit, int n, int x, bool lz, bool tight)
{
    // t_n t_n-1 t_n-2 ... t1 t0
    // <------------------------

    if (n == 0) return 1;

    if (x != -1 && dp[n][x][lz][tight] != -1) return dp[n][x][lz][tight];

    long long res = 0;
    int lim = tight ? (digit[digit.size() - n] - '0') : 9;
    for (int d = 0; d <= lim; d++)
    {
        if ((d == x) && (lz == 0)) continue; // same adjacent digits
        res += f(digit, n-1, d, lz && d == 0, tight && (d == lim));
    }

    return dp[n][x][lz][tight] = res;
}

int32_t main()
{
    long long a, b;
    std::cin >> a >> b;

    std::string digit_a = std::to_string(a - 1);
    std::string digit_b = std::to_string(b);

    std::memset(dp, -1, sizeof(dp));
    long long ans_a = f(digit_a, digit_a.size(), -1, 1, 1);
    std::memset(dp, -1, sizeof(dp));
    long long ans_b = f(digit_b, digit_b.size(), -1, 1, 1);

    std::cout << ans_b - ans_a;
    // long long n;
    // std::cin >> n;
    // std::string digit_n = std::to_string(n);
    // std::cout << f(digit_n, digit_n.size(), -1, 1, 1);
}
