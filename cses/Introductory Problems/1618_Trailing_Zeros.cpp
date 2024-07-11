#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int ans = 0;
    for (int i = 5; n >= i; i *= 5)
        ans += n / i;

    std::cout << ans;
}