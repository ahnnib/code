#include <iostream>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const ll mod = 1e9 + 7;
ll a, b, n;

const int sz = 5;
struct Mat {
    ll m[sz][sz] = {};
} dv;
void pp() {
    for (int i = 0; i < sz; i++) dv.m[i][i] = 1;
}
void printm(Mat m) {
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            cout << m.m[i][j] << " \n"[j == sz-1];
        }
    }
}
Mat operator * (const Mat &a, const Mat &b) {
    Mat res;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                res.m[i][j] += a.m[i][k] * b.m[k][j];
                res.m[i][j] %= mod;
            }
        }
    }
    return res;
}
Mat powm(Mat a, ll b) {
    Mat res = dv;
    for (; b; b >>= 1) {
        if (b & 1) res = res * a;
        a = a * a;
    }
    return res;
}


int main() {
    pp() ;

    cin >> a >> b >> n;

    Mat fi; // f(n-1), f(n), n^2, n, 1
    fi.m[0][0] = a % mod;
    fi.m[0][1] = b % mod;
    fi.m[0][2] = 4;
    fi.m[0][3] = 2;
    fi.m[0][4] = 1;

    Mat cs;
    cs.m[1][0] = cs.m[1][1] = cs.m[2][2] = cs.m[3][3] = cs.m[4][2] = cs.m[4][3] = cs.m[4][4] = 1;
    cs.m[0][1] = cs.m[3][2] = 2;
    cs.m[2][1] = 3;

    Mat kq = fi * powm(cs, n-1);

    // printm(fi);
    // printm(cs);
    // printm(kq);
    cout << kq.m[0][1];
}