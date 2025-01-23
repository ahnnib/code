#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const int N = 20;
const int LEN = 101;
const int MASK = 1<<N;
const int INF = 1e9;
int cost[N][N];
int tmp[LEN][LEN];
int dp[MASK];

int n; string s[LEN];

int main() {
    cin >> n;
    for (int i = 0; i < 2*n; i++) cin >> s[i];

    for (int i = 0; i < 2*n; i++) {
        for (int j = i+1; j < 2*n; j++) {
            int ni = s[i].size(), nj = s[j].size();
            for (int u = 0; u <= ni; u++) {
                for (int v = 0; v <= nj; v++) {
                    tmp[u][v] = INF;
                }
            }
            tmp[0][0] = 0;
            for (int u = 0; u <= ni; u++) {
                for (int v = 0; v <= nj; v++) {
                    if (u < ni) {
                        tmp[u + 1][v] = min(tmp[u + 1][v], tmp[u][v] + 1);
                    }
                    if (v < nj) {
                        tmp[u][v + 1] = min(tmp[u][v + 1], tmp[u][v] + 1);
                    }
                    if (u < ni && v < nj && s[i][u] == s[j][v]) {
                        tmp[u+1][v+1] = min(tmp[u+1][v+1], tmp[u][v] + 1);
                    }
                }
            }
            cost[i][j] = cost[j][i] = tmp[ni][nj];
        }
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int mask = 0; mask < 1<<(2*n); mask++) {
        if (__builtin_popcount(mask) % 2) continue;
        for (int i = 0; i < 2*n; i++) {
            for (int j = 0; j < 2*n; j++) {
                if ((mask >> i) & 1 && (mask >> j) & 1 && i != j) {
                    dp[mask] = min(dp[mask], max(dp[mask ^ (1<<i) ^ (1<<j)], cost[i][j]));
                }
            }
        }
    }

    cout << dp[(1<<(2*n)) - 1];
}