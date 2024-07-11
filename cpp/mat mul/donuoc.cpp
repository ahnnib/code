#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a, x, n) for (int i = x; i <= n; i++) see(a[i]);
#define debug cout << "dfad\n";

struct mat{
    long long m[3][3] = {};
} base;
mat operator * (const mat &m1, const mat &m2) {
    mat res;
    for (int i : {0, 1, 2}) for (int j : {0, 1, 2}) {
        for (int k : {0, 1, 2}) {
            res.m[i][j] += m1.m[i][k] * m2.m[k][j];
        }
    }
    return res;
}
mat powm(mat &a, long long n) {
    if (n == 0) return base;
    if (n == 1) return a;
    mat T = powm(a, n>>1);
    if (n & 1) return T * T * a;
    return T * T;
}
void printm(mat &m) {
    for (int i : {0, 1, 2}) for (int j : {0, 1, 2})
        cout << m.m[i][j] << " \n"[j == 2];
}

signed main()
{
    for (int i : {0, 1, 2}) base.m[i][i] = 1;

    int a, b; long long n; see(a, b, n);
    if (n == 1) return cout << a, 0;
    if (n == 2) return cout << b, 0;

    mat x;
    x.m[0][0] = a; x.m[0][1] = b; x.m[0][2] = 2 * b - a;

    mat y;
    y.m[1][0] = 1; y.m[1][2] = -1;
    y.m[2][1] = 1; y.m[2][2] = 2;

    mat z = powm(y, n-3);
    mat p = x * z;
    // printm(x);
    // printm(z);
    // printm(p);
    putl(p.m[0][2]);
}
// 3 1 -1
/*
Cách 2: Toán
u_n = 1/2(u_n+1 + u_n-1) -> u_n+1 = 2u_n - u_n-1 => Công thức tổng quát
u_n = a (n = 1)
    = b (n = 2)
    = 2u_n-1 - u_n-2 (mọi n > 2)
<=> u_n - u_n-1 = u_n-1 - u_n-2 (mọi n > 2)
=> U là cấp số cộng với công sai k = u2 - u1 = b - a
=> u_n = u_1 + (n-1)k = a + (n-1)(b-a)
signed main()
{
    ll a, b, n; see(a, b, n);
    put(a + (n - 1) * (b - a));
}
*/