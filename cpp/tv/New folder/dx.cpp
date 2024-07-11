#include <iostream>
#include <map>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    freopen("dx.inp", "r", stdin);
    freopen("dx.out", "w", stdout);

    int n;
    std::cin >> n;
    int a[n];
    std::map<long, bool> d;
    for (int i = 0; i < n; i++)
        std::cin >> a[i],
        d[a[i]] = 1;

    int t;
    std::cin >> t;
    while (t--)
    {
        long x;
        std::cin >> x;
        std::cout << (d[x] ? "YES\n" : "NO\n");
    }
}