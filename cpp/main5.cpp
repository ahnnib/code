#include <iostream>
using namespace std;

const int mod = 2004010501;
long long inv(long long i) // snt
{
    return i <= 1 ? i : mod - (long long) (mod / i) * inv(mod % i) % mod;
}

long long expo(long long a, long long b)
{
    if (b == 0) return 1;
    long long t = expo(a, b/2) % mod;
    t = t * t % mod;
    return t * (b % 2 ? a : 1) % mod;
}

int main()
{
    long long n;
    cin >> n;

    cout << ((n % mod * (n + 1) % mod * (2 * n + 1) % mod) % mod * expo(6, mod-2)) % mod;
}