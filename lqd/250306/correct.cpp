#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	freopen("correct.inp", "r", stdin);
	freopen("correct.out", "w", stdout);
	int a, b, c, ans = 0; cin >> a >> b >> c;

	if (c%2 == 0) {
		if (a%2 == 0) {
			ans++, a++;
		}
		if (b%2 == 0) {
			ans++, b--;
		}

		ans += (b-a)/2;
	}
	else {
		int add = c-a%c-1;

		int cycle = (c+1)/2;

		int freq = (b-a)/c;

		a += add+freq*c;

		ans += add/2+add%2+freq*cycle;

		ans += (b-a)/2+(b-a)%2;
	}

	return cout << ans << "\n", 0;
}