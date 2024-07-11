#include <iostream>
#include <map>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("bigtab.inp", "r", stdin);
    freopen("bigtab.out", "w", stdout);
    #endif

    int m, n;
    cin >> m >> n;
    int a[m][n];
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
    {
        cin >> a[i][j];
    }

    /*
    i   j
    u   v

    (i, j)
            (u, v)
    */
    long long sum = 0;
    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int u = i; u < m; u++)
            {
                for (int v = j; v < n; v++)
                {
                    map<int, bool> d;
                    int cnt = 0;
                    for (int u = i; u < m; u++)
                    {
                        for (int v = j; v < n; v++)
                        {

                        }
                    }
                    // for (int x = i; x <= j; x++)
                    // {
                    //     for (int y = u; y <= v; y++)
                    //     {
                    //         if (!d[a[x][y]]) cnt++, d[a[x][y]] = 1;
                    //     }
                    // }
                    if (cnt == 1) ans = max(ans, (long long) (j - i + 1) * (v - u + 1));
                }
            }
        }
    }

    cout << ans;
}
/*
5 5
1 2 3 2 1
2 1 3 2 1
3 1 3 3 1
4 4 2 3 1
4 4 5 5 5

1 2 3 3 3
2 2 3 3 3
3 3 3 3 3
4 4 4 4 4
4 4 5 5 5

(0, 0, 0, 0),
*/