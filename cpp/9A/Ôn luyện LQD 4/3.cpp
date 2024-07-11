#include <iostream>

#define int long long

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

signed main()
{
    int x, y, m;
    std::cin >> x >> y >> m;

    for (int i = 0; i < m; i++)
        x = phi(x) + y;

    std::cout << x;
}