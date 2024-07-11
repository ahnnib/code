#include <iostream>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    int p[n];
    for (int i = 0; i < n; i++)
        std::cin >> p[i];

    std::sort(p, p + n);

    int med = p[n/2];
    long long ans = 0;
    for (int i : p)
        ans += abs(med - i);

    std::cout << ans;
}
