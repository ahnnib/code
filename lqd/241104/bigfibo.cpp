#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const ll mod = 1e9 + 7;

struct mat {
    ll m[2][2] = {};
};
mat operator *(const mat &a, const mat &b) {
    mat res;
    for (int i : {0, 1}) {
        for (int j : {0, 1}) {
            for (int k : {0, 1}) {
                (res.m[i][j] += (a.m[i][k] * b.m[k][j])) %= mod;
            }
        }
    }
    return res;
}
int main() {
    freopen("bigfibo.inp", "r", stdin);
    freopen("bigfibo.out", "w", stdout);
    ll n; cin >> n;
    mat a;
    a.m[0][1] = a.m[1][0] = a.m[1][1] = 1;
    auto powm = [&](mat a, ll n) {
        mat res; res.m[0][0] = res.m[1][1] = 1;
        while (n > 0) {
            if (n & 1) res = res * a;
            a = a * a;
            n >>= 1;
        }
        return res;
    };
    a = powm(a, n);
    cout << a.m[1][1];
}