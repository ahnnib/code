#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const int N = 1e6 + 1;
int L[N];
int main() {
    freopen("trees.inp", "r", stdin);
    freopen("trees.out", "w", stdout);
    int n; cin >> n;
    int h[n];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        if (L[h[i]] == 0) L[h[i]] = i;
    }

    for (int i = N-1; i >= 0; i--) {
        L[i-1] = max(L[i-1], L[i]);
    }
    // L[i] = max(L[i..N])
    // for (int i = 0; i < 10; i++) cout << L[i] << ' '; cout << '\n';

    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, L[h[i]] - i);
    }
    cout << (res == 0 ? -1 : res);
}
/* hack test
4
4 4 4 4
*/
/*
int main()
{
    int n;
    cin >> n;
    pair<int, int> a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a + 1, a + 1 + n);
    int ans = 0, vt = a[1].second;
    for (int i = 2; i <= n; i++)
    {
        ans = max(ans, a[i].second - vt);
        if (a[i].second < vt)
            vt = a[i].second;
    }

    if (ans == 0) cout << -1;
    else cout << ans;
}
*/