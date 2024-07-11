#include <iostream>

#define int long long

signed main()
{
    freopen("BDSNT.inp", "r", stdin);
    freopen("BDSNT.out", "w", stdout);

    int n;
    std::cin >> n;

    bool mark[n+1] = {}; mark[n] = 1;

    for (int x = n; x >= 1; x--)
    {
        if (mark[x]) continue;
        for (int d = 2; ; d++)
        {
            int t = d * x + 1;
            if (t > n) break;
            if (mark[t]) mark[x] = true;
        }
    }

    int res = 0;
    for (int i = 2; i <= n; i++) res += mark[i];

    std::cout << res;
}
