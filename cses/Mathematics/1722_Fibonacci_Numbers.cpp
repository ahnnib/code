#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1e9 + 7;

struct mat {
    ll m[2][2] = {};
};
mat operator * (mat &a, mat &b) {
    mat c;
    for (int d : {0, 1}) for (int k : {0, 1})
        for (int u : {0, 1})
            (c.m[d][k] += a.m[d][u] * b.m[u][k]) %= mod;
    return c;
}

int main() {
    ll n; cin >> n;

    if (n == 0) return cout << 0, 0;

    mat a, res;
    a.m[0][1] = a.m[1][0] = a.m[1][1] = 1;
    res.m[0][0] = res.m[1][1] = 1;

    n -= 1; for (; n > 0; n >>= 1) {
        if (n & 1) res = res * a;
        a = a * a;
    }

    cout << res.m[1][1];
}