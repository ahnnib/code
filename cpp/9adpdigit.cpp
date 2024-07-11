#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define int long long

int dp[20][2][180];

int dequy(int i, vector<int> &dig, bool tight, int sum) {
    // if (i < 0) return sum;
    if (i == dig.size()-1) return sum;
    if (dp[i][tight][sum] != -1 && !tight) return dp[i][tight][sum];
    int lim = (tight ? dig[i] : 9);
    int res = 0;
    for (int d = 0; d <= lim; d++) {
        bool new_tight = (d == dig[i] ? tight : 0);
        res += dequy(i+1, dig, new_tight, sum + d);
    }

    if (!tight) dp[i][tight][sum] = res;

    return res;
}

int solve_num(int num) {
    vector<int> dig;
    memset(dp, -1, sizeof(dp));
    while (num) dig.push_back(num % 10), num /= 10;
    // reverse(dig.begin(), dig.end());

    // return dequy(dig.size()-1, dig, 1, 0);
    return dequy(0, dig, 1, 0);
}

void solve() {
    // int a, b; cin >> a >> b;

    // cout << solve_num(b) - solve_num(a-1);
    int a; cin >> a; cout << solve_num(a);

    cout << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    // long long NTT; cin >> NTT; while (NTT--) {
    //     solve();
    // }
    solve();
}
