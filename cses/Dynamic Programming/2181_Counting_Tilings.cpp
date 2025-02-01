#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const ll mod = 1e9 + 7;
const int MAXN = 10;
const int MAXM = 1000;
const int LEN = 1 << (MAXN + 1);
ll dp[MAXM + 1][LEN]; // number of ways to fill column i -> m based on last column state (mask)
int n, m;

void generateMask(int curMask, int nextMask, int row, vector<int> &masks) {
    if (row > n) {
        masks.push_back(nextMask);
        return;
    }
    if (curMask & (1<<row)) { // occupied -> skip
        generateMask(curMask, nextMask, row + 1, masks);
    }
    if (row != n) { // 2x1 tile
        if (((curMask & (1<<row)) == 0) && ((curMask & (1<<(row+1))) == 0)) {
            generateMask(curMask, nextMask, row + 2, masks);
        }
    }
    if (!(curMask & (1<<row))) { // not occupied -> fill
        generateMask(curMask, nextMask | (1<<row), row + 1, masks);
    }
}

ll f(int i, int mask) {
    if (i > m) {
        return mask == 0;
    }
    if (dp[i][mask] != -1) {
        return dp[i][mask];
    }
    ll res = 0;
    vector<int> masks;
    generateMask(mask, 0, 1, masks);
    for (auto newMask : masks) {
        res = res + f(i + 1, newMask);
        res %= mod;
    }
    return dp[i][mask] = res;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    cout << f(1, 0);
}