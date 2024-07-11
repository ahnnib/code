#include <iostream>
#include <map>

int main()
{
    int n;
    std::cin >> n;
    int a[n+1];
    std::map<int, int> d[n+1];
    for (int i = 1; i <= n; i++)
        std::cin >> a[i],
        d[a[i]][i]++;

    std::cout << d[2][3] << '\n';
    // for (auto a : d)
    // {
    //     for (int i = 1; i <= n; i++)
    //         std::cout << a[i] << ' ';
    //     std::cout << '\n';
    // }
    // int l = 1;
    // int ans = 0;
    // for (int r = 1; r <= n; r++)
    // {
    //     if (d[a[r]][r] >= 3)
    //         while (l <= r && d[a[r]][r] >= 3) l++;

    //     ans += n - r + 1;

    //     std::cout << l << ' ' << r << ' ' << ans << '\n';
    // }

    // std::cout << ans;
}
