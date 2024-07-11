#include <iostream>
#include <math.h>
using namespace std;

#define int long long

int ans(int n, int k) {
    int t = (n + 1) / 2;
    if (k <= t) return (k * 2 - 1);
    else return 2 * ans(n / 2, k - t);
}

void solve() {
    int n, k; cin >> n >> k;

    cout << ans(n, k);

    cout << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    long long t; cin >> t; while (t--) {
        solve();
    }
}