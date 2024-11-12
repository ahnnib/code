#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 500;

ll a[N+5], dp[N+5][N+5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("samepair.inp", "r", stdin);
    // freopen("samepair.out", "w", stdout);

    int n; cin >> n; n++;

    for (int x = 1; x <= n; x++) cin >> a[x];

    for (int x = 1; x <= n; x++) {
        dp[x][x+2] = a[x]*a[x+1]*a[x+2];
    }
    for (int x = 3; x <= n; x++) {
        for (int y = 1; x+y <= n; y++) {
            int l = y, r = x+y; dp[l][r] = 1e18;
            for (int z = l+1; z <= r-1; z++) {
                dp[l][r] = min(dp[l][r], dp[l][z-1]+dp[z+1][r]+)
            }
        }
    }
    return cout << dp[1][n] << "\n", 0;
}