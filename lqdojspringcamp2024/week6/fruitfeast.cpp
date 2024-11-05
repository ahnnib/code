#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    int w, a, b; cin >> w >> a >> b;

    bool dp[w+1][2] = {}; // dp[i][j]: co 1 con heo khoi luong i va j=0/1 : ngu/chua ngu
    dp[0][0] = 1;
    for (int j : {0, 1}) {
        for (int i = 0; i <= w; i++) {
            if (dp[i][j] == 0) continue;
            if (i + a <= w) dp[i + a][j] = 1;
            if (i + b <= w) dp[i + b][j] = 1;
            if (j == 0) dp[i/2][1] = 1;
        }
    }
    int res = 0;
    for (int i = 0; i <= w; i++) {
        if (dp[i][0] || dp[i][1]) {
            res = max(res, i);
        }
    }
    cout << res;
}