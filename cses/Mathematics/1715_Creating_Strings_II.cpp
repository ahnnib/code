#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

const ll m = 1e9 + 7;
ll fac[1000001];

int main() {
    string s; cin >> s;

    ll cnt[123] = {};
    fac[0] = 1;
    for (ll i = 1; i <= s.size(); i++) {
        fac[i] = fac[i-1] * i % m;
    }

    for (char i : s) cnt[i]++;
    ll P = fac[s.size()], Q = 1;
    for (int i = 97; i < 123; i++) {
        (Q *= fac[cnt[i]]) %= m;
    }

    ll b = m-2, T = 1;
    while (b) {
        if (b & 1) (T *= Q) %= m;
        (Q *= Q) %= m;
        b >>= 1;
    }
    cout << P * T % m;
}