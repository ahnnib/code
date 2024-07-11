#include <iostream>

bool f(int a, int b)
{
    return ((a + b) % 3 == 0);
}

int main()
{
    short a, b, c;
    std::cin >> a >> b >> c;

    if (f(a, b) || f(a, c) || f(b, c)) std::cout << "YES";
    else std::cout << "NO";
}