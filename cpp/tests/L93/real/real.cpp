#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    freopen("real.inp", "r", stdin);
    freopen("real.out", "w", stdout);

    int n;
    std::cin >> n;
    bool a[n+1];
    int d0[n+1] = {}, d1[n+1] = {};
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        d0[i] = d0[i-1]; d1[i] = d1[i-1];
        if (a[i] == 0) d0[i]++;
        if (a[i] == 1) d1[i]++;
    }

    // for (int i = 1; i <= n; i++) std::cout << d0[i] << ' ';
    // std::cout << '\n';
    // for (int i = 1; i <= n; i++) std::cout << d1[i] << ' ';

    int q;
    std::cin >> q;
    while (q--)
    {
        int l, r;
        std::cin >> l >> r;
        if (d0[r] - d0[l-1] == d1[r] - d1[l-1])
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }

}