#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

long long dp[20][2][180];
long long f(vector<int> &digit, int ind, bool tight, long long sum) {
    // base case
    if (ind == -1) return sum;
    // already calculated
    if (dp[ind][tight][sum] != -1 && tight != 1) return dp[ind][tight][sum];
    // calculate limit
    int k = (tight ? digit[ind] : 9);
    long long res = 0;
    for (int i = 0; i <= k; i++) {
        res += f(digit, ind-1, (digit[ind] == i ? tight : 0), sum + i);
    }
    // check if satisfied -> memoize
    if (!tight) dp[ind][tight][sum] = res;
    // return
    return res;
}

signed main()
{
    memset(dp, -1, sizeof(dp));

    int t; cin >> t; while (t--) {
        long long a, b; cin >> a >> b;

        a -= 1;

        vector<int> sq_a, sq_b;
        while (a) sq_a.push_back(a % 10), a /= 10; while (b) sq_b.push_back(b % 10), b /= 10;
        // reverse(sq_a.begin(), sq_a.end()); reverse(sq_b.begin(), sq_b.end());

        cout << f(sq_b, sq_b.size()-1, 1, 0) - f(sq_a, sq_a.size()-1, 1, 0) << '\n';
    }
    // long long x; cin >> x;
    // vector<int> sq_x; while (x) sq_x.push_back(x % 10), x /= 10;
    // reverse(sq_x.begin(), sq_x.end());
    // cout << f(sq_x, 0, 1, 0);
}