#include <iostream>
#include <map>
#include <vector>
#include <numeric>
using namespace std;

#define debug cout << "dfad\n";

#define int long long
const int mod = 1e9 + 7;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    int a[n+1];

    for (int i = 1; i <= n; i++) a[i] = 1;

    map<int, map<int, int>> da;
    // tai a[i] co duoc map ptich cua a[i]
    int res = 1;
    while (q--)
    {
        int x, y;
        cin >> x >> y;

        a[x] = y;

        map<int, int> dy;
        for (int i = 2; i * i <= y; i++)
            while (y % i == 0)
                y /= i,
                dy[i]++;
        if (y != 1) dy[y]++;

        da[a[x]] = dy;

        vector<int> d;
        for (int i = 1; i <= n; i++)
        {
            map<int, int> x = da[a[i]];
            cout << a[i] << ' ';
            for (auto i : x) d[i.first] += i.second;


        }
        cout << '\n';
        int res = 1;
        cout << "accumulate: " << accumulate(d.begin(), d.end(), 0) << '\n';
        // for (auto i : d) cout << i << ' ';
        // cout << '\n';
        // for (auto i : d) res *= (i + 1);
        // for (auto i : dy) cout << i.first << ": " << i.second << '\n';
        // cout << '\n';
        // cout << res << '\n';
    }
}
/*
5 3
1 3
1 4
2 5

2^2 1 1 1 1

*/