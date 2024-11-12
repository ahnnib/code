#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";


const ll mod = 1e9 + 7;
const int sz = 2;
struct Mat {
    ll M[sz][sz] = {};
} dv;
Mat operator *(const Mat &a, const Mat &b) {
    Mat res;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
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
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            cout << M.M[i][j] << " \n"[j == sz-1];
        }
    }
}
void pp() {
    for (int i = 0; i < sz; i++) dv.M[i][i] = 1;
}

ll n;
void sol() {
    cin >> n;

    if (n == 1) {
        cout << "1 ";
        return;
    }
    if ((n - 2) % 3 == 0) {
        cout << "0 ";
        return;
    }

    Mat fi, cs;
    fi.M[0][0] = 2; fi.M[0][1] = 3;
    cs.M[0][0] = cs.M[0][1] = cs.M[1][0] = 1;
    cs.M[1][1] = 2;

    fi = fi * powM(cs, n / 3 - 1);

    cout << fi.M[0][n % 3] << ' ';
}
int main() {
    pp();
    freopen("apstairs.inp", "r", stdin);
    freopen("apstairs.out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--) sol();
}