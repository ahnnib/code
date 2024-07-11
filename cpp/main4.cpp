#include <iostream>
#include <set>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
//	freopen("BAI1.inp", "r", stdin);
//	freopen("BAI1.out", "w", stdout);

	set< pair<ll, ll> > res;

	int t = 1;
	cin >> t;
	while (t--) {
		ll s, k; cin >> s >> k;
		ll cnt = 0;
		for (ll n = 2; n * n <= 2*s; n++) {
			if (2*s % n == 0) {
				ll t = 2*s/n - (n-1) * k;
//				cout << n << ' ' << t << '\n';
				if (t % 2 == 0 && t > 0) {
					ll t1 = t / 2;
					ll t2 = n;
					res.insert({min(t1, t2), max(t1, t2)});
				}
				if (n != 2*s/n) {
					ll t = 2 * s / (s/n) - (s/n - 1) * k;
					if (t % 2 == 0 && t > 0) {
						ll t1 = t / 2;
						ll t2 = s/n;
						res.insert({min(t1, t2), max(t1, t2)});
					}
//					cout << n << ' ' << t << '\n';
				}
			}
		}
		for (auto i : res) cout << i.first << ' ' << i.second << '\n';
	}
}
