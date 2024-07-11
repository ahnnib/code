#include <iostream>

struct problem
{
    std::string name;
    int cnt;
    int AC;
};

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    freopen("server.inp", "r", stdin);
    freopen("server.out", "w", stdout);

    int n;
    std::cin >> n;

    problem problems[n+1];

    for (int i = 1; i <= n; i++)
        std::cin >> problems[i].name,
        problems[i].cnt = 0,
        problems[i].AC = 0;

    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        int p, c;
        std::cin >> p >> c;
        problems[p].cnt++;
        if (c == 100) problems[p].AC++;
    }

    // for (auto i : problems)
    // {
    //     std::cout << i.name << ' '
    //               << i.cnt << ' '
    //               << i.AC << '\n';
    // } std::cout << '\n';

    int maxcnt = 0, mincnt = 1e5, ac = 0;
    for (int i = 1; i <= n; i++)
    {
        if (problems[i].cnt > maxcnt)
            maxcnt = i;
        if (problems[i].cnt < mincnt)
            mincnt = i;
        if (problems[i].AC > ac)
            ac = i;
    }

    std::cout << maxcnt << ' ' << mincnt << ' ' << ac;
}