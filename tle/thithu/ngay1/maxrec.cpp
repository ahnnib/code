#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

bool mxm(ll &x, ll y) { return x < y ? x = y, 1 : 0; }

int main() {
	freopen("maxrec.inp", "r", stdin);
	freopen("maxrec.out", "w", stdout);

	ll n, m, x, y; cin >> n >> m >> x >> y;
	ll res = 0;
	mxm(res, (n) * (y-1));
	mxm(res, (n) * (m-y));
	mxm(res, (m) * (x-1));
	mxm(res, (m) * (n-x));
	cout << res;
}


