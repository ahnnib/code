#include <iostream>
using namespace std;

const long long mod = 1e9 + 7;

long long expo(long long a, long long b)
{
    if (b == 0) return 1;
    long long t = expo(a, b/2) % mod;
    t = t * t % mod;
    return t * (b % 2 ? a : 1) % mod;
}

int main()
{
    int n;
    cin >> n;
    while (n --> 0)
    {
        long long a, b;
        cin >> a >> b;
        cout << expo(a, b) << '\n';
    }
}