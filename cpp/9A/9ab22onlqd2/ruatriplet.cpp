#include <iostream>
#include <map>
#include <algorithm>
#include <set>

#define int long long

int dist(int x1, int x2)
{
    return abs(x2 - x1) - 1;
}

signed main()
{
    #define task "ruatriplet"
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    int n, q;
    std::cin >> n >> q;
    std::set<int> a;
    std::map<int, int> d;
    for (int i = 1; i <= n; i++)
    {
        int x;
        std::cin >> x;
        a.insert(x);
        d[x]++;
    }
    // for (auto i : a) std::cout << i << ' ';
    int sa = (int)a.size();

    std::map<int, int> ind;
    int pos = 1;
    for (auto i : a)
        ind[i] = pos,
        pos++;

    int ans = 0;
    for (int x = 1; x * x <= q; x++)
    {
        if (q % x == 0)
        {
            int j1 = q / x,
                j2 = q / -x;

            if (x * j1 == q && ind[x] != 0 && ind[j1] != 0)
                ans += dist(ind[x], ind[j1]) * d[x] * d[j1];
            if (-x * j2 == q && ind[-x] != 0 && ind[j2] != 0)
                ans += dist(ind[-x], ind[j2]) * d[-x] * d[j2];
        }
    }
    std::cout << ans;
} // x * (x-1) / 2
/*
5 10
1 2 3 5 10

4

5 12
1 3 4 12 24

2

8 12
-1 0 1 2 2 3 4 6

4

9 12
-1 0 1 2 2 3 4 6 6

8

10 12
-1 0 1 2 2 3 4 6 6 6

12
*/
