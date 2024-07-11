#include <iostream>
using namespace std;

#define int long long

void solve() {
    int n; cin >> n; int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    int year = a[0];
    for (int i = 1; i < n; i++) {
        int t = year % a[i];
        if (t == 0) year += a[i];
        else year += a[i] - t;
    }

    cout << year << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t; cin >> t; while (t--) {
        solve();
    }
}