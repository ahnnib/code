#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

void solve() {
    int n, m; cin >> n >> m;
    int a[n+1]; for (int i = 0; i < n; i++) cin >> a[i];

    bool res[m+1] = {};
    for (int i = 1; i < (1<<n); i++) {
        ll sum = 0;
        for (int j = n-1; j >= 0; j--) {
            if (i & (1<<j)) sum += a[j];
        }
        // cout << sum << '\n';
        for (int k = sum; k <= m; k += sum) res[k] = 1;
    }
    for (int i = 1; i <= m; i++) cout << res[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
}
