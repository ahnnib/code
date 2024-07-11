#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a, x, n) for (int i = x; i <= n; i++) see(a[i]);
#define debug cout << "dfad\n";
const long long mod = 1e9 + 7;

struct mat{
    long long m[3][3] = {};
};
mat operator * (const mat &a, const mat &b) {
    mat res;
    for (int i : {0, 1, 2}) for (int j : {0, 1, 2}) {
        for (int k : {0, 1, 2}) {
            res.m[i][j] += a.m[i][k] * b.m[k][j];
            res.m[i][j] %= mod;
        }
    }
    return res;
}
mat powm(mat a, long long n) {
    if (n == 1) return a;
    mat T = powm(a, n>>1);
    T = T * T;
    if (n & 1) return T * a;
    else return T;
}

void printm(mat &m) {
    for (int i : {0, 1, 2}) for (int j : {0, 1, 2})
        cout << m.m[i][j] << " \n"[j == 2];
}

signed main()
{
    long long n; see(n);

    if (n == 0) return cout << 1, 0;
    if (n == 1) return cout << 2, 0;


    mat a;
    a.m[0][0] = 1; a.m[0][1] = 1; a.m[0][2] = 2;

    mat b;
    b.m[0][0] = 0; b.m[0][1] = 1; b.m[0][2] = 1;
    b.m[1][0] = 1; b.m[1][1] = 1; b.m[1][2] = 1;
    b.m[2][0] = 0; b.m[2][1] = 0; b.m[2][2] = 1;

    mat c = a * powm(b, n-1);
    put(c.m[0][2]);
    // printm(c);
}
/*
f[i] = f[i-1] + f[i-2]
s[i] = s[i-1] + f[i]

f[i-2], f[i-1], s[i-1] | f[i-1], f[i], s[i]
*/