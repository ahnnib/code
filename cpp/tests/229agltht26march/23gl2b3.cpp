#include <iostream>
#include <algorithm>

int main()
{
    // freopen("climbstair.inp", "r", stdin);
    // freopen("climbstair.out", "w", stdout);

    int n, m;
    std::cin >> n >> m;
    int a[n+1];
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        a[i] = std::max(a[i-1], a[i]);
    }

    while (m--)
    {
        int t;
        std::cin >> t;
        std::cout << (std::upper_bound(a + 1, a + n + 1, t) - a + 1) - 2 << '\n';
    }
}