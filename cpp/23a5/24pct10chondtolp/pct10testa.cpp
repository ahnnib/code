#include <iostream>
using namespace std;

#define int long long

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int n, q, p;
    cin >> n >> q >> p;

    int a[n+1] = {};
    int d[n+1] = {};

    while (q --> 0)
    {
        int l, r, v;
        cin >> l >> r >> v;

        d[l] += v; d[r+1] -= v;
    }

    for (int i = 1; i <= n; i++)
    {
        d[i] += d[i-1];
        a[i] += d[i] + a[i-1];
    }

    while (p --> 0)
    {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[l-1] << '\n';
    }
}