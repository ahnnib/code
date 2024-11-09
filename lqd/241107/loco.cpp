#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll n, M;

const int sz = 3;
struct Mat {
    ll m[sz][sz] = {};
} dv;
Mat operator *(const Mat &a, const Mat &b) {
    Mat res;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                (res.m[i][j] += (a.m[i][k] * b.m[k][j])) %= M;
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

    freopen("loco.inp", "r", stdin);
    freopen("loco.out", "w", stdout);

    cin >> n >> M;

    Mat fi;
    fi.m[0][0] = 1; fi.m[0][1] = 2; fi.m[0][2] = 4;
    Mat cs;
    cs.m[1][0] = cs.m[2][1] = cs.m[0][2] = cs.m[1][2] = cs.m[2][2] = 1;

    fi = fi * powM(cs, n-3);

    cout << fi.m[0][2];
}