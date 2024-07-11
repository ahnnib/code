#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 4e5 + 5;
ll n, q, t, w;
ll x, y, z;
ll a[N], d[N], b[N];
ll res;
/*
5 3 1 5
1 2 3 4 5
1 2 3
2 3 4
3 4 5

4 9 12 9 5

7
*/
bool check (int tar) {
    /*
    với đáp án tar, kiểm tra xem có cách chọn vị trí tấn công cho ra kq tar
    với mỗi i, nếu a
    */
	ll l = 1, r = n, dif;
	for (ll i = 1; i <= n; i++) {
		dif = a[i] - tar;
		if (dif <= 0) continue;
		l = max (l, i - w + dif);
		r = min (r, i + w - dif);
	}
	return l <= r;
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen ("ATTACK.inp", "r", stdin);
	freopen ("ATTACK.out", "w", stdout);
	cin >> n >> q >> t >> w;
	a[0] = -1e18;
	for (int i = 1; i <= n; i++) cin >> a[i];
	while (q--) {
		cin >> x >> y >> z;
		d[x] += z; d[y + 1] -= z;
	}
	for (int i = 1; i <= n; i++) {
		d[i] += d[i - 1];
		a[i] += d[i];
	}
	if (t == 0) {
		for (int i = 1; i <= n; i++)
			res = max (res, a[i]);
		cout << res;
		return 0;
	}
	ll l = -2e9, r = 2e9, m;
	while (l <= r) {
		m = (l + r ) / 2;
		if (check (m)) {
			res = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	cout << res;
}