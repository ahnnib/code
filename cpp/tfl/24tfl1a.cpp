#include <iostream>
#include <cmath>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a, x, n) for (int i = x; i <= n; i++) cin >> a[i];
#define puta(a, x, n) for (int i = x; i <= n; i++) cout << a[i] << " \n"[i == n];
#define debug cout << "dfad\n";
#define ll long long
ll n, v, h;

void sub1() {
    // bool a[n+1] = {};
    // for (int i = 1; i <= n; i++) {
    //     for (int j = i; j <= n; j += i) a[j] = !a[j];
    //     // cout << i << ": "; puta(a, 1, n);
    // }
    // int cnt = 0;
    // puta(a, 1, n);
    // for (int i = v; i <= h; i++) cnt += a[i];
    // cout << cnt;
    cout << sqrt(h) - sqrt(v - 1);
}
void sub2() {
    cout << floor(sqrt(h)) - ceil(sqrt(v)) + 1;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("24tfl1a.inp", "r", stdin);
    freopen("24tfl1a.out", "w", stdout);
    #endif
    see(n, v, h);

    sub1(); cout << '\n';
    sub2();
    // if (n <= 1000) sub1();
    // else sub2();

    // bool a[51] = {};
    // for (int i = 1; i <= 50; i++) {
    //     cout << i << ": ";
    //     for (int j = i; j <= 50; j += i) a[j] = !a[j];
    //     puta(a, 1, 50);
    // }
}