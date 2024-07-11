#include <iostream>
using namespace std;

const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;

long long fact[MAX], ifact[MAX];

long long expo(long long a, long long b)
{
    if (b == 0) return 1;
    long long t = expo(a, b/2) % mod;
    t = t * t % mod;
    return t * (b % 2 ? a : 1) % mod;
}
long long nCr(long long n, long long k)
{
    return fact[n] * ifact[k] % mod * ifact[n-k] % mod;
}

int main()
{
    // preprocess
    fact[0] = 1; for (long long i = 1; i < MAX; i++) fact[i] = fact[i-1] * i % mod;
    ifact[MAX-1] = 1ll * expo(fact[MAX-1], mod-2);
    for (long long i = MAX-2; i >= 0; i--) ifact[i] = ifact[i+1] * (i+1) % mod;

    int n; cin >> n;
    while (n--)
    {
        long long a, b; cin >> a >> b;
        cout << nCr(a, b) << '\n';
    }

}