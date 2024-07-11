#include <iostream>
using namespace std;

#define int long long
int d[100001];

signed main() {
    #ifndef ONLINE_JUDGE
    #else
    freopen("fwoler.inp", "r", stdin);
    freopen("fwoler.out", "w", stdout);
    #endif

    int n, m; cin >> n >> m;

    int res = 0;

    int a[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (d[a[i]] == 0) res++;
        d[a[i]]++;
    }

    for (int i = 0; i < m; i++) {
        int p, v; cin >> p >> v;
        d[a[p]]--;
        d[v]++;
        if (d[a[p]] == 0) res--;
        if (d[v] == 1) res++;
        a[p] = v;

        cout << res << '\n';
    }
}
