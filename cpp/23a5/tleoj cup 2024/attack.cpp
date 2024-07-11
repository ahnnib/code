#include <iostream>
#include <algorithm>
using namespace std;

#define int long long

const int N = 4e5 + 5;

int n, q, t, w;
int l, r, c;
int a[N], d[N];
int res;

bool check (int tar) { //
	int left = 1, right = n, dif;
	for (int i = 1; i <= n; i++) {
		dif = a[i] - tar;
		if (dif <= 0) continue;
		left = max (left, i - w + dif);
		right = min (right, i + w - dif);
	}
	return left <= right;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("attack.inp", "r", stdin);
    freopen("attack.out", "w", stdout);
    #endif

    cin >> n >> q >> t >> w;
    for (int i = 1; i <= n; i++) cin >> a[i];

    while (q--)
    {
        cin >> l >> r >> c;
        d[l] += c; d[r+1] -= c;
    }
    for (int i = 1; i <= n; i++)
        d[i] += d[i-1],
        a[i] += d[i];

    if (t == 0)
    {
        for (int i = 1; i <= n; i++) res = max(res, a[i]);
        cout << res;
        return 0;
    }

    int l = -2e9, r = 2e9, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res << '\n';
}