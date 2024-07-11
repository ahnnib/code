#include <iostream>

#define int long long

signed main()
{
    #define task "demcap"
    #ifndef ONLINE_JUDGE
    #else
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    #endif

    int n, k;
    std::cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    int ans = 0;
    for (int l = 0; l < n; l++)
    {
        int minn = 9223372036854775807, maxx = -9223372036854775807-1ll;
        for (int r = l; r < n; r++)
        {
            minn = std::min(minn, a[r]);
            maxx = std::max(maxx, a[r]);

            if (maxx - minn <= k) ans++;
        }
    }

    std::cout << ans;
}