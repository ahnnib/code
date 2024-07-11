#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
template<class X, class Y> bool mxm(X &x, const Y &y) { return (x < y ? x = y, 1 : 0); }
template<class X, class Y> bool mnm(X &x, const Y &y) { return (x > y ? x = y, 1 : 0); }
#define seea(a, x, n) for (int i = x; i <= n; i++) cin >> a[i];
#define puta(a, x, n) for (int i = x; i <= n; i++) cout << a[i] << " \n"[i == n];
#define debug cout << "dfad\n";
#define ll long long

const ll MAX = 1e18;
/*
dp[i][j]: tại vị trí i thực hiện j thao tác đc tổng bé nhất là bao nhiêu
xét đoạn con độ dài d + 1: ta có thể tối thiểu tổng của đoạn bằng d thao tác
ct truy hồi: dp[i][j] = min(dp[i + d + 1][j + d] + (d + 1) * x) (với x là phần tử bé nhất trong đoạn d)
*/

void solve() {
    int n, k; see(n, k);
    ll a[n + 5] = {}; seea(a, 1, n);

    ll dp[n + 5][k + 5]; for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++) dp[i][j] = MAX;
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            mnm(dp[i + 1][j], dp[i][j] + a[i + 1]);
            ll mn = a[i + 1];
            for (ll d = 1; i + d < n && j + d <= k; d++) {
                int p = i + d + 1;
                mnm(mn, a[p]);
                mnm(dp[p][j + d], dp[i][j] + (d + 1) * mn);
            }
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= k; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    ll res = MAX;
    for (int j = 0; j <= k; j++) mnm(res, dp[n][j]);
    putl(res);
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int pbt = 1;
    cin >> pbt;
    while (pbt--) {
        solve();
    }
}