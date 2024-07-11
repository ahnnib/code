#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    long long a[n];
    std::cin >> a[0];
    long long ans = 0;
    for (int i = 1; i < n; i++)
    {
        std::cin >> a[i];

        if (a[i] < a[i-1])
            ans += a[i-1] - a[i],
            a[i] += a[i-1] - a[i];
    }
    std::cout << ans;
}