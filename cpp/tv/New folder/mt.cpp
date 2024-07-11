#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    freopen("mt.inp", "r", stdin);
    freopen("mt.out", "w", stdout);

    int n, m;
    std::cin >> n >> m;
    char mt[n+1][m+1];
    // goi d[i][j] la so ki tu ... trong o {(1, 1) -> (i, j)};
    int d[123][n+1][m+1] = {};
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            std::cin >> mt[i][j];

            for (int c = 'a'; c <= 'z'; c++)
                d[c][i][j] = d[c][i-1][j] + \
                             d[c][i][j-1] - \
                             d[c][i-1][j-1] + \
                             (c == mt[i][j]);
        }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++)
    //         std::cout << d['a'][i][j] << ' ';
    //     std::cout << '\n';
    // }
    int t;
    std::cin >> t;
    while (t--)
    {
        int i, j, u, v;
        std::cin >> i >> j >> u >> v;

        char ans; int m = 0;
        for (int c = 'z'; c >= 'a'; c--)
        {
            int cnt = d[c][u][v] - \
                      d[c][i-1][v] - \
                      d[c][u][j-1] + \
                      d[c][i-1][j-1];

            if (cnt >= m) ans = c, m = cnt;
        }

        std::cout << ans << '\n';
    }
}
/*
adg
bax

1 1 1
1 2 2

0 0 0
1 1 1

0 0 1
0 0 1

0 0 0
0 0 0
*/