#include <iostream>
#include <vector>
using namespace std;

#define int long long

signed main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("e.inp", "r", stdin);
    freopen("e.out", "w", stdout);
    #endif

    // cyclic : -
    // acyclic: +

    int k; cin >> k; int a[k+1][3] = {};
    for (int i = 1; i <= k; i++) cin >> a[i][0];
    for (int i = 1; i <= k; i++) cin >> a[i][1];
    for (int i = 1; i <= k; i++) cin >> a[i][2];

    int jj;
    int dp[k+1][3] = {}; // dp[i][j] dừng tại môi trường j đc tối đa bao nhiêu điểm
    for (int i = 1; i <= k; i++) {
        for (int j : {0, 1, 2}) {
            // case j
            dp[i][j] = dp[i-1][j];
            // case j+1: 0->1, 1->2, 2->0
            jj = (j + 1) % 3;
            dp[i][j] = max(dp[i][j], dp[i-1][jj] + a[i][j]);
            // case j-1: 0->2, 2->1, 1->0
            jj = (j > 0 ? j - 1 : 2);
            dp[i][j] = max(dp[i][j], dp[i-1][jj] - a[i][j]);
        }
    }
    cout << max(dp[k][0], max(dp[k][1], dp[k][2]));
}
/*

*/