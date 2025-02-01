#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const int N = 16;
int n;
int a[N][N];
vector<ll> dp(1 << (N + 1), -1e18); // best score partitioning rabbits in mask
ll s[1 << (N + 1)]; // s[mask]: sum of all a_ij with i < j in mask

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int mask = 0; mask < 1<<n; mask++) {
        vector<int> members;
        for (int j = 0; j < n; j++) {
            if (mask & (1<<j)) {
                members.push_back(j);
            }
        }
        for (int u = 0; u < members.size(); u++) {
            for (int v = u + 1; v < members.size(); v++) {
                s[mask] += a[members[u]][members[v]];
            }
        }
    }

    dp[0] = 0;
    for (int S = 1; S < 1<<n; S++) {
        ll best = s[S];
        for (int T = (S - 1) & S; T; T = (T - 1) & S) { // loop over non-empty subsets of S
            best = max(best, dp[S ^ T] + s[T]);
        }
        dp[S] = best;
    }

    cout << dp[(1<<n) - 1];
}