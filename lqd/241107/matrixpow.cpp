#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int m; ll n;

const ll mod = 1e9 + 7;
const int sz = 100;
struct Mat {
    ll M[sz][sz] = {};
} dv;
Mat operator *(const Mat &a, const Mat &b) {
    Mat res;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                (res.M[i][j] += (a.M[i][k] * b.M[k][j])) %= mod;
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
void printM(Mat &M) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << M.M[i][j] << " \n"[j == m-1];
        }
    }
}
void pp() {
    for (int i = 0; i < m; i++) dv.M[i][i] = 1;
}

int main() {
    freopen("matrixpow.inp", "r", stdin);
    freopen("matrixpow.out", "w", stdout);

    cin >> m >> n;

    pp();

    Mat a;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a.M[i][j];
        }
    }
    a = powM(a, n);
    printM(a);
}