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
void pp() {
    for (int i = 0; i < sz; i++) dv.m[i][i] = 1;
}


int main() {
    freopen("tudien.inp", "r", stdin);
    freopen("tudien.out", "w", stdout);
    pp() ;

    int n; cin >> n;

    Mat fi;
    for (int i = 0; i < 4; i++) fi.m[0][i] = 1;
    Mat cs;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i != j) cs.m[i][j] = 1;
        }
    }
    fi = fi * powM(cs, n-1);
    cout << fi.m[0][3];
}