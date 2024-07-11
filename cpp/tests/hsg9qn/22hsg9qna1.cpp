#include <iostream>
using namespace std;

const long long m = 1e9 + 7;

long long expo(long long a, long long b)
{
    if (b == 0) return 1;
    long long t = expo(a, b/2) % m;
    t = t * t % m;
    return t * (b % 2 ? a : 1) % m;
}

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("spow.inp", "r", stdin);
    freopen("spow.out", "w", stdout);
    #endif

    long long a, n;
    cin >> a >> n;

    cout << (a % m + n % m) % m << '\n';

    cout << expo(a, n);
}