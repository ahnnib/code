#include <iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("transport.inp", "r", stdin);
    freopen("transport.out", "w", stdout);
    #endif

    int n, s;
    cin >> n >> s;
    int a[n+1] = {};
    for (int i = 1; i <= n; i++) cin >> a[i];

    int dp[s+1] = {};
    for (int i = 1; i <= n; i++)
        for (int j = s; j > a[i]; j--)
            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
    cout << dp[s];
}
/*
5 16
3 4 2 5 6
*/