#include <iostream>
using namespace std;

int n, m, q, k, x;
int a[1007][1007];

void sub1() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) cnt += (a[i][1] == x);
    cout << cnt << '\n';
}
void sub234() {
    long long dp[n + 5][m + 5] = {}; // dp[i][j]: đến ô (i, j) có thể đi qua nhiều nhất bao nhiêu ô thỏa mãn
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = (a[i][j] == x);
            dp[i][j] += max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1]));
        }
    }

    cout << dp[n][m] << '\n';
}

void solve()
{
    cin >> x;

    if (m == 1) sub1();
    else sub234();
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    #ifndef ONLINE_JUDGE
    #else
    freopen("robot.inp", "r", stdin);
    freopen("robot.out", "w", stdout);
    #endif

    cin >> n >> m >> q >> k;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
        a[i][j] = a[i][j] % k;
    }

    while (q--) {
        solve();
    }
}
