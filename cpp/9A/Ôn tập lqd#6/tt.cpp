#include <iostream>

int main()
{
    freopen("tt.inp", "r", stdin);
    freopen("tt.out", "w", stdout);

    int n;
    std::cin >> n;

    long long ans = 0;
    for (long long i = 1; i <= n; i++)
        ans += i * (i + 1) / 2;

    std::cout << ans << '\n';
}