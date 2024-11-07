#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll n, M;

const int sz = 2;
struct Mat {
    ll m[sz][sz] = {};
} dv;
Mat operator *(const Mat &a, const Mat &b) {
    Mat res;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                res.m[i][j] += (a.m[i][k] * b.m[k][j]);
            }
        }
    }
    return res;
}
Mat powM(Mat a, ll n) {
    Mat res = dv;
    for (; n > 0; n >>= 1) {
        if (n & 1) res = res * a;
        a = a * a;
    }
    return res;
}
void printM(Mat &m) {
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            cout << m.m[i][j] << " \n"[j == sz-1];
        }
    }
}

int main() {
    for (int i = 0; i < sz; i++) dv.m[i][i] = 1;

    freopen("donuoc.inp", "r", stdin);
    freopen("donuoc.out", "w", stdout);

    ll a, b, n; cin >> a >> b >> n;

    Mat fi;
    fi.m[0][0] = a; fi.m[0][1] = b;
    Mat cs;
    cs.m[1][0] = 1;
    cs.m[0][1] = -1;
    cs.m[1][1] = 2;

    fi = fi * powM(cs, n-2);

    cout << fi.m[0][1];
}