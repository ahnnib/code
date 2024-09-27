/*
kq bài toán là số tập nghiệm x thỏa mãn
x1 + x2 + .. + xm = n
đưa về bài toán số cách nhét n-1 số 0 vào giữa m + n - 1 số 1 tượng trưng cho x1, x2, .., xn
11101100..111
=> (m+n-1)C(n-1)
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

const ll mod = 1e9 + 7;

int main() {
    ll n, m; cin >> n >> m;
    ll P = 1, Q = 1, T = 1;
    for (ll i = m+n-1; i > m; i--) (P *= i) %= mod;
    for (int i = 2; i < n; i++) (Q *= i) %= mod;
    for (ll b = mod-2; b; b >>= 1) {
        if (b&1) (T *= Q) %= mod;
        (Q *= Q) %= mod;
    }
    cout << P * T % mod;
}