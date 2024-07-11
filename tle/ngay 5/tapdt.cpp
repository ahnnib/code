#include <iostream>
#include <math.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;
int n, k, l[200001];

void sub1() {
    int l1 = l[0], l2 = l[1];
    if (l1 < l2) swap(l1, l2);
    int res = 0;
    for (int s1 = 1; s1 <= n - l1 + 1; s1++) {
        int s2 = max(s1 - l2 + 1, 1ll) + l2 - 1;
        int e2 = min(s1 + l1-1 + l2-1, n);
        // cout << s2 << ' ' << e2 << '\n';
        res += e2 - s2 + 1;
        res %= mod;
    }
    cout << res;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("tapdt.inp", "r", stdin);
    freopen("tapdt.out", "w", stdout);
    #endif

    cin >> n >> k; for (int i = 0; i < k; i++) cin >> l[i];

    if (k == 2) sub1();
}