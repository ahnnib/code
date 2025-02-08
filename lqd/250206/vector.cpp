#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int n, m;
void sub125() {
    int u;
    vector<int> dp;
    for (int i = 0; i < n; i++) {
        cin >> u;
        vector<int>::iterator it = lower_bound(dp.begin(), dp.end(), u);
        if (it == dp.end()) dp.push_back(u);
        else *it = u;
    }
    cout << dp.size();
}
void sub346() {
    int v[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
        sort(v[i], v[i] + m);
    }

    auto check = [&](int x, int y) -> bool { // v[x] < v[y]
        bool res = true;
        for (int j = 0; res && (j < m); j++) {
            res &= v[x][j] < v[y][j];
        }
        return res;
    };
    int dp[n][m] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (check(j, i)) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, dp[i][m]);
    }
    cout << res;
}

int main() {
    cin >> n >> m;
    if (m == 1) sub125();
    else sub346();
}