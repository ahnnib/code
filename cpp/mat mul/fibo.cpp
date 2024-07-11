#include <iostream>
#include <algorithm>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a, x, n) for (int i = x; i <= n; i++) see(a[i]);
#define debug cout << "dfad\n";
#define int long long
const int mod = 111539786;
// gcd(f[i], f[j]) = f[gcd(i, j)]
struct mat {
    int m[2][2] = {};
};
mat operator * (const mat &a, const mat &b) {
    mat res;
    for (int i : {0, 1}) for (int j : {0, 1}) {
        for (int k : {0, 1}) {
            res.m[i][j] += a.m[i][k] * b.m[k][j];
            res.m[i][j] %= mod;
        }
    }
    return res;
}
mat powm(mat a, int b) {
    if (b == 1) return a;
    mat T = powm(a, b>>1);
    T = T * T;
    if (b & 1) return T * a;
    else return T;
}

void printm(mat mm) {
    for (int i : {0, 1}) {
        for (int j : {0, 1}) {
            cout << mm.m[i][j] << " \n"[j == 1];
        }
    }
}

signed main()
{
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        mat a;
        a.m[0][0] = 1; a.m[0][1] = 2;
        mat b;
        b.m[0][0] = 0;
        b.m[0][1] = b.m[1][1] = b.m[1][0] = 1;
        // 0 1
        // 1 1
        mat c = a * powm(b, n-1);
        putl(c.m[0][0]);
    }
}
