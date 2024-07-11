#include <iostream>
#include <cmath>
using namespace std;

#define int long long

const int MAX = 4e6 + 1;
int n, a, b, _d[MAX];

long long expo(long long a, long long b, long long mod) {
    if (b == 0) return 1;
    long long t = expo(a, b>>1, mod) % mod;
    return t * t % mod * (b & 1 ? a : 1) % mod;
}
void pp() { for (int i = 1; i < MAX; i++) for (int j = i; j < MAX; j += i) _d[j]++; }
int f(int i) {
    int res = 1;
    for (int j = 2; j <= i; j++) {
        if (i % j == 0) {
            res *= j;
            while (i % j == 0) i /= j;
        }
    }
    return res;
}
int d(int i) { return _d[i]; }

bool prime(long long n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (long long i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i+2) == 0) return 0;
    return 1;
}
void sub1() {
    int res = 0; for (int i = 2; i * i <= n; i++) res += prime(i); cout << res;
}
void sub2() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (f(i) <= n / i && a <= d(i) && d(i) <= b) res++;
    }
    cout << res;
}

signed main()
{
    pp();

    cin >> n >> a >> b;

    if (a == b && a == 2) sub1();
    else sub2();
}