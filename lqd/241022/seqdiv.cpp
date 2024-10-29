#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const ll mod = 1e9 + 7;
const int N = 101, M = 200001;
int n, k;
int dp[N][M]; vector<int> uoc[M];

ll f(int n, int tt) {
    if (n == 0) {
        return 1;
    }

    if (dp[n][tt] != -1) return dp[n][tt];

    ll res = 0;
    for (int i : uoc[tt]) {
        (res += f(n - 1, i)) %= mod;
    }

    if (tt != 0) {
        for (int i = 2 * tt; i <= k; i += tt) {
            (res += f(n - 1, i)) %= mod;
        }
    }

    return dp[n][tt] = res;
}

int main() {
    freopen("seqdiv.inp", "r", stdin);
    freopen("seqdiv.out", "w", stdout);

    memset(dp, -1, sizeof dp);
    for (int i = 1; i < M; i++)
        for (int j = 2 * i; j < M; j += i)
            uoc[j].push_back(i);

    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        uoc[0].push_back(i);
    }

    cout << f(n, 0);
}