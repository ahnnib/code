#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("uocchung.inp", "r", stdin);
    freopen("uocchung.out", "w", stdout);
    #endif

    long long a, b; cin >> a >> b;
    long long t = gcd(a, b);

    if (t == 1) return cout << -1, 0;
    for (long long i = 2; i * i <= t; i++) if (t % i == 0) return cout << t / i, 0;
    cout << 1;
}