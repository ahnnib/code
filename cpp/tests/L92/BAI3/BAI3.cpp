#include <iostream>

int main()
{
    freopen("BAI3.INP", "r", stdin);
    freopen("BAI3.OUT", "w", stdout);

    int t;
    std::cin >> t;

    while (t--)
    {
        long long n;
        std::cin >> n;
        std::cout << n / 2 + 1 << '\n';
    }
}

/*
2
6
9

4 5
*/