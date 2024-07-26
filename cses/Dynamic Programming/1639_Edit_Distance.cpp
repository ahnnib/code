#include <iostream>
#include <vector>
using namespace std;

int main() {
    string n, m; cin >> n >> m;
    int nn = n.size(), nm = m.size();
    vector< vector<int> > dp(nn+1, vector<int>(nm+1, 5000));
    dp[0][0] = 0;
    for (int i = 0; i <= nn; i++) {
        for (int j = 0; j <= nm; j++) {
            if (i) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            if (j) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            if (i && j) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (n[i-1] != m[j-1]));
        }
    }
    cout << dp[nn][nm];
}