#include <bits/stdc++.h>
using namespace std;

#define int long long
/*
3
1 3 2 0
2 -1 -2

2 6 1 5 7 8 0
4 -5 4 2 1 -8

*/
void solve() {
    int n; cin >> n; int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    bool c = 1;
    for (int l = 0; l < n && c; l++) {
        int sum = 0;
        for (int r = l; r < n && c; r++) {
            if ((l % 2) != (r % 2)) sum -= a[r];
            else sum += a[r];

            if (sum == 0) c = 0;
        }
    }

    cout << (c ? "NO" : "YES");

    cout << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    long long NTT; cin >> NTT; while (NTT--) {
        solve();
    }
}