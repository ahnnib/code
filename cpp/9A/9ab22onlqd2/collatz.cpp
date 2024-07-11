#include <iostream>

int main()
{
    #define task "collatz"
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    int t;
    std::cin >> t;
    while (t--)
    {
        long long x;
        std::cin >> x;
        int cnt = 0;
        while (x > 1)
        {
            if (x % 2) x = 3 * x + 1;
            else x /= 2;
            cnt++;
        }
        std::cout << cnt << '\n';
    }
}