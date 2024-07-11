#include <iostream>
#include <cmath>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a, x, n) for (int i = x; i <= n; i++) see(a[i]);
#define debug cout << "dfad\n";
#define int long long
int x, n, m;

struct mat {
    int m[2][2] = {};
} base;
int mul(int a, int b) {
    if (b == 0) return 0;
    if (b == 1) return a;
    int T = mul(a, b>>1) % m;
    if (b & 1) return (T + T + a) % m;
    else return (T + T) % m;
}
mat operator * (const mat &a, const mat &b) {
    mat res;
    for (int i : {0,1}) for (int j : {0,1}) {
        for (int k : {0,1}) {
            res.m[i][j] += mul(a.m[i][k], b.m[k][j]);
            res.m[i][j] %= m;
        }
    }
    return res;
}
mat powm(mat &x, int n) {
    if (n == 0) return base;
    if (n == 1) return x;
    mat T = powm(x, n>>1);
    if (n & 1) return T * T * x;
    return T * T;
}
void printm(mat &m) {
    for (int i : {0,1}) for (int j : {0,1}) {
        cout << m.m[i][j] << " \n"[j == 1];
    }
}

signed main()
{
    see(x, n, m);

    // f[i] = f[i-1] * len + x * 1
    mat a;
    a.m[0][0] = x%m; a.m[0][1] = x%m;

    int len = 1, xx = x; while (xx) xx /= 10, len *= 10;

    mat b;
    b.m[0][0] = len; b.m[1][0] = b.m[1][1] = 1;

    mat c = a * powm(b, n-1);
    // printm(c);
    putl(c.m[0][0]);
}