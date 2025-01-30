/*
Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

Number of workers and job: N <= 20
C(i,j): cost incurred on assigning ith Person to jth Job.

Sample Input
4
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4
Sample Output
13

dp[i][mask]: min cost if assign job i+1 -> n to workers (mask)
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int n, c[21][21];
ll dp[21][1<<21];
ll f(int i, int mask) {
    if (i == n) {
        return 0;
    }
    if (dp[i][mask] != -1) return dp[i][mask];
    ll res = 1e18;
    for (int j = 0; j < n; j++) {
        if ((1<<j) & mask) {
            res = min(res, c[j][i] + f(i + 1, (1<<j) ^ mask));
        }
    }
    return dp[i][mask] = res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout << f(0, (1<<n) - 1);
}