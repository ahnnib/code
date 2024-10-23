#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const int N = 1e3 + 1;
const int INF = 2e9;
int m, n, a[N][N], dp[N][N];
vector< pair<int, int> > trace;

void dq(int u, int v) {

    if (v == 1) {
        trace.push_back({u, v});
        return;
    }

    for (int i = max(1, u-1); i <= min(m, u+1); i++) {
        if (dp[i][v - 1] + a[u][v] == dp[u][v]) {
            trace.push_back({u, v});
            dq(i, v - 1);
            return;
        }
    }
}

int main() {

    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];


    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) dp[i][j] = -INF;
    }
    for (int i = 1; i <= m; i++) dp[i][1] = a[i][1];

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            for (int t : {-1, 0, 1}) {
                if (i + t >= 1 && i + t <= m)
                    dp[i][j] = max(dp[i][j], dp[i + t][j - 1] + a[i][j]);
            }
        }
    }


    int res = -INF, max_i = 0;
    for (int i = 1; i <= m; i++) {
        if (dp[i][n] > res) {
            res = dp[i][n];
            max_i = i;
        }
    }
    cout << res << '\n';

    dq(max_i, n);

    for (auto i = trace.end() - 1; i >= trace.begin(); i--) {
        cout << i->first << ' ' << i->second << '\n';
    }
}