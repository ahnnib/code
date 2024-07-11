#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

const ll mod = 1e9 + 7;
int n, a, b, c, d;

const int sz = 4;
struct mat { ll m[sz][sz] = {}; } dv;
void init() { for (int i = 0; i < sz; i++) dv.m[i][i] = 1; }
mat operator * (const mat &a, const mat &b) {
    mat res;
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
mat powm(mat a, int n) {
    mat res = dv;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}
void printm(mat &m) { for (int i = 0; i < sz; i++) { for (int j = 0; j < sz; j++) cout << m.m[i][j] << ' '; cout << '\n'; } }

void solve() {
    cin >> n >> a >> b >> c >> d;
    mat fi; fi.m[0][0] = 1; fi.m[0][1] = 2; fi.m[0][2] = 3; fi.m[0][3] = 4;
//    printm(fi);
    mat A, B, C, D;
    for (int i = 0; i < 3; i++) A.m[i+1][i] = B.m[i+1][i] = C.m[i+1][i] = D.m[i+1][i] = 1;
    A.m[0][3] = B.m[1][3] = C.m[2][3] = D.m[3][3] = a;
    A.m[1][3] = B.m[2][3] = C.m[3][3] = D.m[0][3] = d;
    A.m[2][3] = B.m[3][3] = C.m[0][3] = D.m[1][3] = c;
    A.m[3][3] = B.m[0][3] = C.m[1][3] = D.m[2][3] = b;
//    printm(A); cout << '\n';
//    printm(B); cout << '\n';
//    printm(C); cout << '\n';
//    printm(D); cout << '\n';
    mat cs = A * B * C * D;
//    printm(cs); cout << '\n';
    cs = powm(cs, (n - 1) / 4);
//    printm(cs); cout << '\n';
    mat kq = fi * cs;
    cout << kq.m[0][(n - 1) % 4] << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("fib4.inp", "r", stdin);
    freopen("fib4.out", "w", stdout);

    init() ;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
