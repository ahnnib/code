#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

struct T { int a, b, c; };
int main() {
    freopen("stadium.inp", "r", stdin);
    freopen("stadium.out", "w", stdout);
    int n; cin >> n; T ds[n]; for (int i = 0; i < n; i++) cin >> ds[i].a >> ds[i].b >> ds[i].c;
    sort(ds, ds + n, [](T &x, T &y) { return x.b < y.b; });
    int dp[n] = {};
    int res = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = ds[i].c;
        for (int j = 0; j < i; j++) {
            if (ds[j].b <= ds[i].a) dp[i] = max(dp[i], dp[j] + ds[i].c);
        }
        res = max(res, dp[i]);
    }
    cout << res;
}