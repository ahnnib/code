#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    long long max_here = 0, max_so_far = -9223372036854775807ll-1;
    while (n--)
    {
        int a;
        std::cin >> a;

        max_here = std::max((long long) a, max_here + a);
        max_so_far = std::max(max_so_far, max_here);
    }

    std::cout << max_so_far;
}
