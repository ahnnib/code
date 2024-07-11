#include <iostream>

#define int long long

bool prime(int n)
{
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return 0;

    return 1;
}

signed main()
{
    int x;
    std::cin >> x;

    if (prime(x)) return std::cout << 1, 0;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return std::cout << x/i, 0;

}
