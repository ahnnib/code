#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll n;
vector<ll> dp(1000001, -1e9);
ll cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
    freopen("led.inp", "r", stdin);
    freopen("led.out", "w", stdout);
    cin >> n;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (i - cost[j] >= 0) {
                dp[i] = max(dp[i], dp[i - cost[j]] + j);
            }
        }
    }
    cout << dp[n];
}