#include <iostream>

bool prime(long long n)
{
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (long long i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}

int main()
{
    long long n;
    std::cin >> n;
    std::cout << (prime(n) ? "YES" : "NO");
}