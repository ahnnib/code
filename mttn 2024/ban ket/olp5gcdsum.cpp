#include <iostream>
using namespace std;

#define int long long
const int mod = 998244353ll;
const int inv = 499122177ll;
long long a, b;

void sub1() {
    int res = 0;
    while (b != 0) {
        while (a >= b) res += a, a -= b, res %= mod;
        swap(a, b);
    }
    cout << res % mod;
}
void sub3() {
    int x = a / b;
    int sum = ((x % mod) * ((x + 1) % mod)) % mod;
    sum = sum * inv % mod;
    cout << (b % mod * sum) % mod;
}
void sub4() {
    int res = 0;
    while (b != 0) {
        int r = a / b, m = a % b;

        int sum = ((r % mod) * ((r + 1) % mod)) % mod;
        sum = sum * inv % mod;

        res += sum * (b % mod) + (m % mod * r % mod) % mod;
        res %= mod;
        a = a % b;
        swap(a, b);
    }

    cout << res;
}

signed main()
{
    cin >> a >> b;
    if (a < b) swap(a, b);
    // int aa = a, bb = b;

    if (a % b == 0) sub3();
    else if (a <= 10000 && b <= 10000) sub1();
    else sub4();
    // sub1(); cout << '\n';
    // a = aa, b = bb;
    // sub4();
}