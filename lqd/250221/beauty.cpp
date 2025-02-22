#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll i, n, s = 0, kq = -1e18, a[300005], p[2][300005];

int main () {
	freopen("beauty.inp", "r", stdin);
	freopen("beauty.out", "w", stdout);
	cin >> n;
	for (i = 1; i <= n; i++) cin >> a[i];
	p[0][0] = 0;
	p[1][0] = 0;
	for (i = 1; i <= n; i++) {
		s += a[i];
		p[0][i] = p[0][i - 1];
		p[1][i] = p[1][i - 1];
		
		if (i >= 4) {
			if (i % 2 == 0) {
				kq = max (kq, s - p[0][i - 4]);
			}
			else {
				kq = max (kq, s - p[1][i - 4]);
			}
		}
		
		if (i % 2 == 0) p[0][i] = min (p[0][i], s);
		if (i % 2 == 1) p[1][i] = min (p[1][i], s);
		
	}
	cout << kq;
}