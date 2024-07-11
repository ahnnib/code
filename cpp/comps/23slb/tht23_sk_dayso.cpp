#include <iostream>
#include <algorithm>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, l, r;
    cin >> n >> l >> r;
    int a[n + 1];
    int d[n + 1] = {};
    for (int i = 1; i <= n; i++)
        cin >> a[i],
        d[i] = d[i-1] + a[i];

    int ans = -1e14;

    for (int i = 1; i <= n; i++) cout << d[i] << ' '; cout << '\n';
    for (int i = 1; i <= n - r + 1; i++)
    {
        int j = (max_element(d + i + l - 1, d + i + r - 1) - d + 1);
        cout << i << ' ' << j << '\n';
        ans = max(ans, d[j] - d[i-1]);
        // for (int j = i + l - 1; j <= i + r - 1; j++)
        // {
        //     ans = max(ans, d[j] - d[i-1]);
        //     cout << i << ' ' << j << ' ' << d[j] - d[i-1] << '\n';
        // }
    }

    cout << ans;
}
/*
5 2 3
1 3 -1 5 -1
*/