#include <iostream>

int main()
{
    freopen("beautiful.inp", "r", stdin);
    freopen("beautiful.out", "w", stdout);

    std::string x;
    std::cin >> x;

    bool c = 0;

    for (int i = x.size()-1; i > 0; i--)
        if (x[i-1] > x[i])
            c = 1;

    std::cout << (c ? "DEP" : "KHONG");
}