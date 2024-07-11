#include <iostream>

int main()
{
    long n;
    std::cin >> n;
    long tmp = 0;
    for (int i = 1; i < n; i++)
    {
        int a;
        std::cin >> a;
        tmp += a;
    }
    std::cout << n * (n + 1) / 2 - tmp;
}