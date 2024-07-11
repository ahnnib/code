#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a, x, n) for (int i = x; i <= n; i++) cin >> a[i];
#define puta(a, x, n) for (int i = x; i <= n; i++) cout << a[i] << " \n"[i == n];
#define debug cout << "dfad\n";
#define ll long long

const ll mod = 1e9 + 7;

const int sz = 5;
struct mat { ll m[sz][sz] = {}; } base; void init() { for (int i = 0; i < sz; i++) base.m[i][i] = 1; }
mat operator * (const mat &a, const mat &b) {
    mat res;
    for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++) {
        for (int k = 0; k < sz; k++) {
            res.m[i][j] += a.m[i][k] % mod * (b.m[k][j] % mod);
            res.m[i][j] %= mod;
        }
    }
    return res;
}
mat powm(mat &a, ll n) {
    if (n == 0) return base;
    if (n == 1) return a;
    mat T = powm(a, n>>1);
    if (n & 1) return T * T * a;
    else return T * T;
}
void printm(mat &m) {
    for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++) cout << m.m[i][j] << " \n"[j == sz-1];
}

void solve() {
    ll n; see(n);

    // [ f[n-2], f[n-1], f[n], g[n-1], c ] -> [ f[n-1], f[n], f[n+1], g[n], c ]
    // f1, f2, f3, g2, c
    if (n == 1) {
        cout << "7\n";
        return;
    }

    mat a;
    a.m[0][0] = 1; a.m[0][1] = 5; a.m[0][2] = 17; a.m[0][3] = 35; a.m[0][4] = 2;
    // printm(a);
    mat b;
    b.m[1][0] = b.m[2][1] = b.m[2][3] = b.m[4][3] = b.m[4][4] = 1;
    b.m[1][2] = 2; b.m[2][2] = 3; b.m[3][3] = 4;
    // printm(b);
    mat c = a * powm(b, n-2);
    // printm(c);
    putl(c.m[0][3]);
}

signed main()
{
    init();

    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    // solve();
    int pbt; cin >> pbt; while (pbt--) {
        solve();
    }
}
/*
#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a, x, n) for (int i = x; i <= n; i++) cin >> a[i];
#define puta(a, x, n) for (int i = x; i <= n; i++) cout << a[i] << " \n"[i == n];
#define debug cout << "dfad\n";
#define ll long long

const ll mod = 1e9 + 7;

const int sz = 4;
struct mat { ll m[sz][sz] = {}; } base; void init() { for (int i = 0; i < sz; i++) base.m[i][i] = 1; }
mat operator * (const mat &a, const mat &b) {
    mat res;
    for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++) {
        for (int k = 0; k < sz; k++) {
            res.m[i][j] += a.m[i][k] % mod * (b.m[k][j] % mod);
            res.m[i][j] %= mod;
        }
    }
    return res;
}
mat powm(mat &a, ll n) {
    if (n == 0) return base;
    if (n == 1) return a;
    mat T = powm(a, n>>1);
    if (n & 1) return T * T * a;
    else return T * T;
}
void printm(mat &m) {
    for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++) cout << m.m[i][j] << " \n"[j == sz-1];
}

void solve() {
    ll n; see(n);

    // [ f[n-2], f[n-1], g[n-1], c ] -> [ f[n-1], f[n], g[n], c ]
    // f1, f2, g2, c
    if (n <= 0) {
        cout << "-1\n";
        return;
    }
    if (n == 1) {
        cout << "7\n";
        return;
    }

    mat a;
    a.m[0][0] = 1; a.m[0][1] = 5; a.m[0][2] = 35; a.m[0][3] = 2;
    // printm(a);
    mat b;
    b.m[1][0] = b.m[3][2] = b.m[3][3] = 1;
    b.m[0][1] = b.m[0][2] = 2;
    b.m[1][1] = b.m[1][2] = 3;
    b.m[2][2] = 4;
    // printm(b);
    mat c = a * powm(b, n-2);
    // printm(c);
    putl(c.m[0][2]);
}

signed main()
{
    init();

    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    // solve();
    int pbt; cin >> pbt; while (pbt--) {
        solve();
    }
}
*/