#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define lld long double
#define ull unsigned long long
#define left(a, v) lower_bound(a.begin(), a.end(), v)-a.begin()
#define right(a, v) upper_bound(a.begin(), a.end(), v)-a.begin()
#define print(a) for (auto const& x : a) cout << x << " "; cout << "\n";
#define get_an_ac ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define compress(a) sort(a.begin(), a.end()); a.resize(unique(a.begin(), a.end())-a.begin());
#define print_map(a) for (auto const& x : a) cout << x.fi << " " << x.se << "\n"; cout << "\n";
using namespace std;
const ll lim = 1000000;
const ll sussy_number = 69420;
const double pi = acos(-1);
// Sieve of Eratosthenes.
ll sang[lim+5];
void eratos_sieve() {
	sang[0] = sang[1] = 1;
	for (ll x = 4; x <= lim; x += 2) sang[x] = 1;
	for (ll x = 6; x <= lim; x += 3) sang[x] = 1;
	for (ll x = 5; x <= lim; x += 6) {
		if (sang[x] == 0) {
			for (ll y = x*2; y <= lim; y += x) sang[y] = 1;
		}
		if (sang[x+2] == 0) {
			for (ll y = (x+2)*2; y <= lim; y += (x+2)) sang[y] = 1;
		}
	}
}
// Indian multiplication (?).
ll mul(ll a, ll b, ll m) {
	ll ans = 0;
	while (b > 0) {
		if (b%2 == 1) ans = (ans+a)%m;
		a = (a+a)%m, b /= 2;
	}
	return ans;
}
// Exponentiation by squaring.
ll expo(ll a, ll b, ll m) {
	ll ans = 1;
	while (b > 0) {
		if (b%2 == 1) ans = (ans*a)%m;
		a = (a*a)%m, b /= 2;
	}
	return ans;
}
// Prime checking using miller rabin.
ll miller_rabin(ll n) {
	if (n < 2) return false;
	if (n < 4) return true;
	if (n%2 == 0 || n%3 == 0) return false;
	for (ll x = 5; x*x <= n; x += 6) {
		if (n%x == 0 || n%(x+2) == 0) return false;
	}
	return true;
}
// Prime checking using fermat's small theorem.
ll fermat(ll n) {
	if (n < 2) return false;
	if (n == 2 || n == 3) return true;
	if (n%2 == 0 || n%3 == 0) return false;
	if (n == 5 || n == 7 || n == 11) return true;
	if (n%5 == 0 || n%7 == 0 || n%11 == 0) return false;
	if (expo(13, n-1, n) == expo(17, n-1, n) == expo(19, n-1, n) == expo(23, n-1, n) == expo(29, n-1, n) == 1) return true;
	else return false; 
}
// Prime checking using miller rabin (probability ver).
ll fast_miller_rabin(ll n) {
	if (n < 2 || n == 4) return false;
	if (n == 2 || n == 3) return true;
    ll m = n-1, cnt = 0;
	while (m%2 == 0) m /= 2, cnt++;
	for (ll x = 1; x <= 5; x++) {
		ll a = expo(rand()%(n-2)+2, m, n);
		if (a == 1 || a == n-1) continue;
		for (ll y = 0; y < cnt-1; y++) {
            a = (a*a)%n;
            if (a == n-1) break;
        }
        if (a != n-1) return false;
	}
	return true;
}
// Hash template.
ll h[4][lim+5], pw[4][lim+5], bs = 521, mod[4] = {25225019, 45198089, 98187917, 919915999};
ll get_hash(ll l, ll r, ll p) {return (h[p][r]-h[p][l-1]*pw[p][r-l+1]+mod[p]*mod[p])%mod[p];} // 0 <= p <= 3.
void pre_calc() {for (ll p = 0; p <= 3; p++) {pw[p][0] = 1; for (ll x = 1; x <= lim; x++) pw[p][x] = (pw[p][x-1]*bs)%mod[p];}}
// Fenwick tree template.
ll bit1[lim+5], bit2[lim+5]; // Range updates and queries.
void range_update(ll l, ll r, ll gt) {
    for (ll x = l; x <= lim; x += x&-x) bit1[x] += gt, bit2[x] += gt*l;
    for (ll x = ++r; x <= lim; x += x&-x) bit1[x] -= gt, bit2[x]-= gt*r;
}
ll range_query(ll pos) {
    ll tong1 = 0, tong2 = 0;
    for (ll x = pos; x > 0; x -= x&-x) tong1 += bit1[x], tong2 += bit2[x];
    return tong1*(pos+1)-tong2;
}
ll bit[lim+5]; // Point updates and queries.
ll point_update(ll pos, ll val) {
	for (ll x = pos; x <= lim; x += x&-x) bit[x] += val;
}
ll point_query(ll vt) {
	ll tong = 0;
	for (ll x = pos; x > 0; x -= x&-x) tong += bit[x];
	return tong;
}
// __int128 input and output
__int128 input() {
    __int128 n = 0, c = 1;
    char d = getchar();
    while (d < '0' || d > '9') {
        if (d == '-') c = -1;
        d = getchar();
    }
    while (d >= '0' && d <= '9') {n = n*10+d-'0'; d = getchar();}
    return n*c;
}
void print(__int128 n) {
    if (n < 0) {putchar('-'); n *= -1;}
    if (n > 9) print(n/10);
    putchar(n%10+'0');
}
int main() {
	get_an_ac
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	cout << "Hello, world!" << "\n";
	return 0;
}