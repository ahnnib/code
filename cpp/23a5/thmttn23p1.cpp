#include <iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("DRX02T1.inp", "r", stdin);
    freopen("DRX02T1.out", "w", stdout);
    #endif

    int n, k; string s;
    cin >> n >> k >> s;

    int ans = 0;
    for (int l = 0; l < n; l++)
    {
        int r; bool mark[123] = {}; int cnt = 0;
        for (r = l; r < n; r++)
        {
            if (!mark[s[r]]) cnt++, mark[s[r]] = 1;
            if (cnt >= k) break;
        }
        if (cnt >= k) ans += n-1 - r + 1;
    }

    cout << ans;
}
/*
14 11
levanthuckkvoi

1 2 3 4 5 6 7 8 9
*/