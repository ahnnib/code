#include <iostream>
using namespace std;

#define int long long

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n, f, a, b;
        cin >> n >> f >> a >> b;
        int m[n+1] = {}; for (int i = 1; i <= n; i++) cin >> m[i];

        for (int i = 1; i <= n; i++)
        {
            f -= min(a * (m[i] - m[i-1]), b);
        }
        cout << (f <= 0 ? "NO\n" : "YES\n");
    }
}