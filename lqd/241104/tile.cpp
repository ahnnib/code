#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const ll mod = 1e9 + 7;
struct mat {
    ll m[2][2] = {};
} dv;
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
mat powm(mat a, ll n) {
    mat res = dv;
    while (n) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}
void printm(mat &m) {
    for (int i:{0, 1}) for (int j:{0, 1}) {
        cout << m.m[i][j] << " \n"[j == 1];
    }
}

ll n;
void sol() {
    cin >> n;

    mat fi, cs;
    fi.m[0][0] = 1; fi.m[0][1] = 3;
    cs.m[0][1] = 2; cs.m[1][0] = cs.m[1][1] = 1;

    cs = powm(cs, n-2);
    mat kq = fi * cs;

    cout << kq.m[0][1] << '\n';
}

int main() {
    dv.m[0][0] = dv.m[1][1] = 1;

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("tile.inp", "r", stdin);
    freopen("tile.out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--) sol();
}