// Sparse Table implementation for RMQ problem
// https://cses.fi/problemset/task/1647/
#include <iostream>
#include <cmath>
using namespace std;

#define int long long
#define debug cout << "dfad\n";

const int N = 2e5 + 7;
const int LG = 17; // số lớn nhất thỏa 2^LG < N

int st[LG + 1][N];
int n, q, a[N];
/*
j = 0: st[i][j] = a[i]
j > 0: st[i][j] = min(st[i-1][j] , st[i-1][i + 1<<(j-1)]

query: [l, r]
k = (int)log2(r - l + 1)
res = min(st[k][l], st[k][r - (1<<k) + 1])
*/

void pp() {
    for (int i = 1; i <= n; i++) st[0][i] = a[i];
    for (int j = 1; j <= LG; j++)
        for (int i = 1; i + (1<<j) - 1 <= n; i++)
            st[j][i] = min(st[j-1][i], st[j-1][i + (1<<(j-1))]);
}
int solve(int l, int r) {
    int k = __lg(r - l + 1);
    return min(st[k][l], st[k][r - (1<<k) + 1]);
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    cin >> n >> q; for (int i = 1; i <= n; i++) cin >> a[i];

    pp();

    for (int lg = 1; lg <= 5; lg++) {
        for (int i = 1; i <= n; i++) {
            cout << st[lg][i] << ' ';
        }
        cout << '\n';
    }

    while (q--) {
        int l, r; cin >> l >> r; cout << solve(l, r) << '\n';
    }
}
/*
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3

2
1
1
4
*/