#include <iostream>
#include <algorithm>
using namespace std;

/*
1
4 4 8
1 5 10 14
1 1 2 8
*/
void solve() {
    int n, m, k; cin >> n >> m >> k;
    int b[n], c[m];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < m; i++) cin >> c[i];

    sort(b, b + n); sort(c, c + m);

    int res = 0;
    for (int f = 0; f < n; f++) {
        // b[f] + c[s] <= k -> c[s] <= k - b[f]
        int l = 0, r = m-1, mid;
        // trước l: <=
        // sau r: >
        while (l <= r) { // cuoi cung <=
            mid = (l + r) >> 1;
            if (c[mid] <= k - b[f]) l = mid + 1;
            else r = mid - 1;
        }
        // cout << f << ' ' << r << '\n';
        if (r != -1) res += r + 1;
    }

    cout << res;

    cout << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    long long NTT; cin >> NTT; while (NTT--) {
        solve();
    }
}