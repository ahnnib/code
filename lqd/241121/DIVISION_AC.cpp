#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[31][31][501];
int n, m, k;

ll cal(int pos, int x, int du)
{
    if(dp[pos][x][du] != -1)
        return dp[pos][x][du];
    if(pos == 0)
    {
        if(x == n && du == 0)
            return 1;
        return 0;
    }

    ll tmp = 0;
    tmp += cal(pos - 1, x + 1, (du + (1 << pos - 1)) % k);
    tmp += cal(pos - 1, x, du);
    dp[pos][x][du] = tmp;

    return tmp;
}
void DoTest(int question)
{
    cin >> n >> m >> k;
    memset(dp, -1, sizeof dp);
    cout << cal(m + n - 1, 1, (1 << (n + m - 1)) % k);
}

main()
{
    freopen("DIVISION.inp", "r", stdin);    freopen("DIVISION.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q = 1;
    // cin >> q;
    for(int i = 0 ; i < q ; i++)
        DoTest(i);
}
