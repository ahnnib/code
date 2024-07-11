#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    #ifndef ONLINE_JUDGE
    #else
    freopen("ktiepdat.inp", "r", stdin);
    freopen("ktiepdat.out", "w", stdout);
    #endif

    int n, a, x, b, y; cin >> n >> a >> x >> b >> y;
    ll P[n+1] = {}; for (int i = 1; i <= n; i++) cin >> P[i];

    ll dp[a+1][b+1] = {}; // dp[i][j]: số điểm tối đa khi đi i bước x và j bước y
    dp[1][0] = P[x];
    dp[0][1] = P[y];
    dp[1][1] = P[x + y];
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            if (i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j] + P[i * x + j * y]);
            if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1] + P[i * x + j * y]);
        }
    }
    cout << dp[a][b];
}

