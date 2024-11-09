#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int m; ll n;

const ll mod = 1e9 + 7;
const int sz = 3;
struct Mat {
    ll m[sz][sz] = {};
} dv;
Mat operator *(const Mat &a, const Mat &b) {
    Mat res;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                (res.m[i][j] += (a.m[i][k] * b.m[k][j])) %= mod;
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
void printM(Mat &mt) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << mt.m[i][j] << " \n"[j == m-1];
        }
    }
}

int main() {
    for (int i = 0; i < sz; i++) dv.m[i][i] = 1;

    // freopen("matrixpow.inp", "r", stdin);
    // freopen("matrixpow.out", "w", stdout);

    cin >> m >> n;
    Mat a;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a.m[i][j];
        }
    }

    a = powM(a, n);

    printM(a);
}