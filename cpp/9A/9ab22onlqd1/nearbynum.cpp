#include <iostream>

bool prime(long long n)
{
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;

    for (long long i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    } return 1;
}

int main()
{
    #define task "nearbynum"
    #ifndef ONLINE_JUDGE
    #else
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    #endif

    long long n;
    std::cin >> n;
    for (int x = n+1; x <= 2 * n; x++)
        if (prime(x)) return std::cout << x, 0;
}