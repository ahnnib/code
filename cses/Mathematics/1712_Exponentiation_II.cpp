#include <iostream>
using namespace std;

const long long mod = 1e9 + 7;

long long expo(long long a, long long b, long long m)
{
    if (b == 0) return 1;
    long long t = expo(a, b/2, m);
    t = (t % m * t % m) % m;
    return t * (b % 2 ? a : 1) % m;
}

int main()
{
    int n;
    cin >> n;
    while (n --> 0)
    {
        long long a, b, c;
        cin >> a >> b >> c;

        // Fermat's little theorem
        cout << expo(a, expo(b, c, mod-1), mod) << '\n';
    }
}