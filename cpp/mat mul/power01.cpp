#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a, x, n) for (int i = x; i <= n; i++) see(a[i]);
#define debug cout << "dfad\n";
#define int long long

int x, n, m;

struct mat {
    int m[3][3] = {};
} base;
mat operator * (const mat &a, const mat &b) {
    mat res;
    for (int i : {0,1,2}) for (int j : {0,1,2}) {
        for (int k : {0,1,2}) {
            res.m[i][j] += a.m[i][k] * b.m[k][j];
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
    for (int i : {0,1,2}) for (int j : {0,1,2}) {
        cout << m.m[i][j] << " \n"[j == 2];
    }
}

signed main()
{
    for(int i : {0,1,2}) base.m[i][i] = 1;

    see(x, n, m);

    mat a;
    a.m[0][0] = a.m[0][1] = 1; a.m[0][2] = x;
    // printm(a);
    mat b;
    b.m[0][0] = b.m[0][1] = x;
    b.m[1][1] = b.m[2][2] = 1;
    // printm(b);

    mat c = a * powm(b, n);
    // printm(c);
    putl(c.m[0][1]);
}
/*
Cách 2: Toán
tổng cấp số nhân: T = \frac{x^{n+1} - 1}{x - 1}
đáp án: T % m = \frac{x^{n+1} - 1}{x - 1} % m
Theo tính chất modulo: a * b = c -> a%k * b%k = c%k
chọn k = x-1 suy ra T % m = (x^{n+1} - 1) % (m * (x-1))

ll x, n, m;
ll expo(ll a, ll b, ll mod) {
    if (b == 0) return 1;
    ll t = expo(a, b>>1, mod) % mod;
    return t * t % mod * (b & 1 ? a : 1) % mod;
}
signed main()
{
    see(x, n, m);

    m *= x - 1;
    ll res = (expo(x, n+1, m) - 1) % m;
    cout << res / (x-1);
}
Cách 2: đệ quy quay lui
#define ll long long
ll x, n, m;
ll expo(ll a, ll b, ll mod) {
    if (b == 0) return 1;
    ll t = expo(a, b>>1, mod) % mod;
    return t * t % mod * (b & 1 ? a : 1) % mod;
}
ll g(ll x, ll n) {
    if (n == 0) return 1;
    if (n == 1) return (1 + x) % m;
    else if (n & 1) return (1 + x % m * g(x, n-1) % m) % m;
    else return ((1 + expo(x, n>>1, m)) % m * (g(x, n>>1) - 1) % m + 1 + m) % m;

}
signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    cin >> x >> n >> m;
    cout << g(x, n);
}
Cách 2.2: Rút gọn
ll g(ll x, ll n) {
    if (n == 1) return x % m;
    if (n & 1) return x % m * (1 + g(x, n-1)) % m;
    ll t = g(x, n>>1) % m;
    return (t + expo(x, n>>1, m) * t) % m;

}
signed main()
{
    see(x, n, m);
    cout << 1 + g(x, n);
}
*/