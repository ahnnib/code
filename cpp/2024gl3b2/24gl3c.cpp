#include <iostream>
#include <algorithm>
using namespace std;

#define debug cout << "dfad\n";
#define int long long

void solve() {

    int n; cin >> n; int b[n+1] = {}; for (int i = 1; i <= n; i++) cin >> b[i];

    sort(b + 1, b + n + 1);

    int i = 1; while (b[i] == 1) i++;
    int cnt1 = i - 1;

    long long sum = cnt1;
    bool ok = 1;

    for (; i <= n; i++) {
        if (sum < b[i]) { ok = 0; break; }
        sum += b[i];
    }

    cout << (ok ? "YES" : "NO");

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