#include <iostream>

int main()
{
    int32_t t;
    std::cin >> t;
    while (t --> 0)
    {
        long long y, x;
        std::cin >> y >> x;
        std::swap(x, y);

        long long ans = 0;
        if (x >= y)
        {
            long long t = (x-1) * (x-1);
            if (x % 2) ans = t + y;
            else ans = t + x + (x-y);
        }
        if (y > x)
        {
            long long t = (y-1) * (y-1);
            if (y % 2) ans = t + y + (y-x);
            else ans = t + x;
        }

        std::cout << ans << '\n';
    }
}
