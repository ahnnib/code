#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";


const int sz = 3;
const ll mod = 1e9 + 7;
struct Mat {
    ll m[sz][sz] = {};
} dv;
Mat operator *(const Mat &a, const Mat &b) {
    Mat res;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                (res.m[i][j] += a.m[i][k] * b.m[k][j]) %= mod;
            }
        }
    }
    return res;
}
Mat powM(Mat a, ll n) {
    Mat res = dv;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
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
    freopen("mtseq.inp", "r", stdin);
    freopen("mtseq.out", "w", stdout);

    for (int i = 0; i < sz; i++) dv.m[i][i] = 1;
    int m; cin >> m;
    ll n[m];
    for (int i = 0; i < m; i++) cin >> n[i];


    for (int i = 0; i < m; i++) {
        if (n[i] <= 3) cout << n[i] << ' ';
        else {
            Mat fi;
            fi.m[0][0] = 1; fi.m[0][1] = 2; fi.m[0][2] = 3;
            Mat cs;
            cs.m[1][0] = cs.m[2][1] = cs.m[0][2] = 1;
            cs.m[1][2] = -2;
            cs.m[2][2] = 3;

            fi = fi * powM(cs, n[i]-3);

            cout << fi.m[0][2] << ' ';
        }
    }
}