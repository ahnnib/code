#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int dig[5] = {1, 2, 3, 4, 5};

string nth (ll n) {
	string res;
	while (n > 0) {
		res = char(dig[n % 5] + 48) + res;
		n /= 5;
	}
	return res;
}

int main() {
//		ll n; cin >> n;
	for (ll i = 1; i <= 50; i++) {
	ll n = i;
	cout << nth(n) << ' ';
	}
}

