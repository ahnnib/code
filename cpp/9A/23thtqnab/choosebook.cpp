#include <iostream>
#include <algorithm>

int main()
{
    #define task "choosebook"
    #ifndef ONLINE_JUDGE
    #else
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    #endif

    int n, m;
    std::cin >> n >> m;
    long long a[n];
    for (int i = 0; i < n; i++) std::cin >> a[i];

    std::sort(a, a + n);

    long long ans = 1e16;
    for (int i = 0; i < n - m + 1; i++)
        ans = std::min(ans, a[i + m - 1] - a[i]);

    std::cout << ans;
}