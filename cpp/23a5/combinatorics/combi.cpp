// n, k <= 1e5, p <= 1e9 + 7;
#include <iostream>
using namespace std;

const int N = 1e5;
long long fact[N+1], ifac[N+1], ii[N+1], pw[N+1]; // n!, 1/n!, pw[i] = k max, p^k | i!
int t, p;

long long pow(long long a, long long b, int p)
{
    if (b == 0) return 1;
    long long res = pow(a, b/2, p) % p;
    res = res * res % p;
    return res * (b % 2 ? a : 1) % p;
}

void nCr(int n, int k)
{
    long long t = pw[n] - pw[k] - pw[n-k];
    if (t > 0) cout << 0 << '\n';
    else cout << fact[n] * ifac[k] % p * ifac[n-k] % p * pow(p, t, p) % p << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    cin >> t >> p;

    pw[1] = ii[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        ii[i] = i; pw[i] = pw[i-1];
        while (ii[i] % p == 0) ii[i] /= p, pw[i]++;
    }
    fact[0] = fact[1] = 1; for (int i = 2; i <= N; i++) fact[i] = fact[i-1] * ii[i] % p;
    ifac[N] = pow(fact[N], p-2, p) % p;
    for (int i = N-1; i >= 0; i--) ifac[i] = ii[i+1] * ifac[i+1] % p;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        nCr(n, k);
    }
}