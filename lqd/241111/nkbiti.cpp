#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int n, k;
const ll mod = 666777;
ll dp[2][2]; // dp[i][j]: so xau thoa man tai vi tri i co j so 0 lien tiep
// void Dotest(int quest)
// {
//     dp[0][0] = 1;

//     for(int i = 1 ; i <= n ; i++)
//     {
//         for(int j = 0 ; j <= k ; j++)
//             dp[1][j] = 0;

//         for(int j = 0 ; j < k ; j++)
//         {
//             dp[1][0] = (dp[1][0] + dp[0][j]) % mod;
//             dp[1][j + 1] = dp[0][j] % mod;
//         }
//         //cout << dp[0][k] << '\n';
//         dp[1][0] += dp[0][k];

//         for(int j = 0 ; j <= k ; j++)
//             dp[0][j] = dp[1][j];
//     }

//     ll ans = 0;
//     for(int i = 0 ; i <= k ; i++)
//         ans += dp[1][i], ans %= mod;
//     cout << ans;
// }

int main() {
    cin >> n >> k;

}