#include <iostream>
using namespace std;

#define ll unsigned long long
#define debug cout << "dfad\n";

const ll mod = 0xFFFFFFFD;
const ll pmod = 0xFFF8C460;

const int sz = 2;
struct mat { ll m[sz][sz] = {}; } dv, cs; mat powm[61]; // ceil(log2(1e18)) = 60
mat operator * (const mat &a, const mat &b) {
	mat res;
	for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++) for (int k = 0; k < sz; k++)
		res.m[i][j] += a.m[i][k] * b.m[k][j], res.m[i][j] %= pmod;
	return res;
}
void init() {
	// khoi tao ma tran don vi, ma tran co so
	for (int i = 0; i < sz; i++) dv.m[i][i] = 1; cs.m[0][1] = cs.m[1][0] = cs.m[1][1] = 1;
	// tinh truoc cac luy thua ma tran. powm[i]: cs ^ (2^i)
	powm[0] = cs; for (int i = 1; i <= 60; i++) powm[i] = powm[i-1] * powm[i-1];
}
void printm(mat &m) { for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++) cout << m.m[i][j] << " \n"[j == sz-1]; cout << '\n'; }
ll expo(ll a, ll b) { ll res = 1; while (b > 0) { if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1; } return res; }

void solve() {
	ll n;
	cin >> n;
	n -= 1;
	mat kq = dv; int index = 0;
	while (n > 0) {
		if (n & 1) {
			kq = kq * powm[index];
		}
		n >>= 1; index += 1;
	}
	ll t = expo(70, kq.m[0][0]) * expo(421, kq.m[0][1]) % mod;
	cout << ((t - 1) % mod + mod) % mod << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	init() ;

	int tc = 1;
	cin >> tc;
	while (tc--) solve();
}

