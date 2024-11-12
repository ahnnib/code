#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const ll mod = 1e9 + 7;
const int sz = 4;
struct Mat {
    ll m[sz][sz] = {};
} dv;
Mat operator *(const Mat &a, const Mat &b) {
    Mat res;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                (res.m[i][j] += (a.m[i][k] * b.m[k][j])) %= mod;
            }
        }
    }
    return res;
}
Mat powM(Mat a, int n) {
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
void pp() {
    for (int i = 0; i < sz; i++) dv.m[i][i] = 1;
}


int n;
void sol() {
    cin >> n;
    if (n <= 0) {
        cout << "1\n";
        return;
    }

    Mat fi;
    fi.m[0][0] = fi.m[0][1] = fi.m[0][2] = 1; fi.m[0][3] = 2;
    Mat cs;
    cs.m[0][1] = 2;
    cs.m[1][0] = cs.m[1][2] = cs.m[3][2] = cs.m[3][3] = 1;
    cs.m[1][1] = 3;
    cs.m[2][2] = 4;
    fi = fi * powM(cs, n);

    cout << fi.m[0][2] << '\n';
}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pp() ;
    freopen("aba15e.inp", "r", stdin);
    freopen("aba15e.out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--) sol();
}