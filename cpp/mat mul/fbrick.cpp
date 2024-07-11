#include <iostream>
using namespace std;

#define debug cout << "dfad\n";
#define ll long long

ll a2, n, m;

const int sz = 4;
struct mat { ll m[sz][sz] = {}; } dv;
void init() { for (int i = 0; i < sz; i++) dv.m[i][i] = 1; }
mat operator * (mat a, mat b) { mat res;
	for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++)
		for (int k = 0; k < sz; k++) {
			res.m[i][j] += a.m[i][k] * b.m[k][j];
			res.m[i][j] %= m;
		}
		return res; }
mat powm(mat a, int n) { mat res = dv;
	while (n > 0) {
		if (n & 1) res = res * a;
		a = a * a;
		n >>= 1;
	}
return res; }
void printm(mat &m) { for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++) cout << m.m[i][j] << " \n"[j == sz-1]; }
void solve() {
	cin >> a2 >> n >> m;

	if (n == 1) {
		cout << 1 % m << '\n';
		return;
	}

	ll C = 2 * a2;

	mat fi;
	fi.m[0][0] = 1; fi.m[0][1] = 1 * a2 % m; fi.m[0][2] = a2 * (a2%m) % m; fi.m[0][3] = (1 + a2 * (a2%m)) % m;

	mat cs;
	cs.m[0][2] = cs.m[0][3] = 1;
	cs.m[1][1] = -1; cs.m[1][2] = cs.m[1][3] = -2 * C % m;
	cs.m[2][0] = 1; cs.m[2][1] = C % m; cs.m[2][2] = cs.m[2][3] = (C%m * (C%m)) % m;
	cs.m[3][3] = 1;
	cs = powm(cs, n-2);
	// printm(cs);
	mat res = fi * cs;
	// printm(res);
	cout << res.m[0][3] << '\n';
}

signed main()
{
	std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

	init() ;

	int pbt = 1;
	cin >> pbt;
	while (pbt--) {
		solve();
	}
}