#include <iostream>
#include <math.h>
using namespace std;

#define int long long

int xau(int a) {
    int t = sqrt(a);
    return min(abs(t*t - a), abs((t+1)*(t+1) - a));
}

signed main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("seqd.inp", "r", stdin);
    freopen("seqd.out", "w", stdout);
    #endif

    int n, k; cin >> n >> k;
    int res[n+1] = {};
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        res[i] = xau(a);
    }

    // for (int i = 1; i <= n; i++) cout << res[i] << ' '; cout << '\n';

    int sum = 0, ans = 2147483647;
    for (int i = 1; i <= k; i++) {
        sum += res[i];
    }
    for (int i = k+1; i <= n; i++) {
        ans = min(ans, sum);
        sum -= res[i - k]; sum += res[i];
    }
    ans = min(ans, sum);
    cout << ans;

}