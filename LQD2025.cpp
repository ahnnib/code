#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

// mang cong don: s[i] = s[i-1] + f[i]
// mang cong don tren bang
void f() {
	ll s[n][n];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + f[i][j];
		}
	}
	auto query [&](int i, int j, int u, int v) -> ll {
		return s[u][v] - s[u][j-1] - s[i-1][v] + s[i-1][j-1];
	}
}
// cac loai sang
void sieve() {
	// sang nguyen to
	com[0] = com[1] = 1;
	for (int i = 2; i * i < lim; i++) if (com[i] == 0) for (int j = i*i; j < lim; j += i) com[j] = 1;
	// sang uoc
	for (int i = 1; i <= n; i++) for (int j = i; j <= n; j += i) uoc[j] += i;
	// sang tren doan: tu l den r
	vector<bool> isPrime(r - l + 1, true);
	for (int i = 2; i * i <= r; i++) {
		for (int j = max(i*i, (l + i - 1) / i*i); j <= r; j += i) isPrime[j - l] = false;
	}
	/* xets rieng trg hop 1 */ if (1 - l >= 0) isPrime[1 - l] = false;
	auto [&](ll x) query {
		return isPrime[x - l]; // x laf snt
	}
	// chat nhi phan: quan he thu tu yeu. cac loai: chat dung, chat bien trai bien phai, cnp kq, cnp so thuc
	// de quy, meet in the middle
	// dp (thua)
	// knapsack, frog and stone, ...
	// mat mul
	// ds (segtree, BIT, ...)
	// math
}
// phi ham euler, nghich dao modulo
ll phi(ll x) {
	ll res = x;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) while (...) ; res -= res / i;
	}
	if (x > 1) res -= res / x;
	// phi euler 1 -> n
	init: phi[i] = i;
	i = 2 -> n if phi[i] == i for j = i -> n, j += i: phi[j] -= phi[j] / i;
}
// extended euclidean

int main() {

}


