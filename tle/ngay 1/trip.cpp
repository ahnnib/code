// https://lqdoj.edu.vn/problem/longestpath/editorial
#include <iostream>
#include <vector>
using namespace std;

#define debug cout << "dfad\n";
const int N = 2e5 + 1;
int l[N], r[N];
vector<int> dp(N, -1);

int dfs(int u) {
    if (dp[u] != -1) return dp[u];

    dp[u] = 0;
    for (int v = l[u]; v <= r[u]; v++) {
        dp[u] = max(dp[u], dfs(v) + 1);
    }
    return dp[u];
}

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("trip.inp", "r", stdin);
    freopen("trip.out", "w", stdout);
    #endif

    int n; cin >> n;
    for (int i = 1; i < n; i++) cin >> l[i];
    for (int i = 1; i < n; i++) cin >> r[i];


    int res = 0;
    for (int node = 1; node <= n; node++) {
        res = max(res, dfs(node));
    }

    cout << res;
}