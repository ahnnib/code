#include <iostream>
using namespace std;

const long long mod = 10;
long long expo(long long a, long long b)
{
    if (b == 0) return 1;
    long long t = expo(a, b/2) % mod;
    t = t * t % mod;
    return t * (b % 2 ? a : 1) % mod;
}

int main() // a^b % 10
{
    string A; long long B;
    cin >> A >> B;

    int a = A[A.size()-1] - 48, b = B % 100;

    if (B == 0) cout << 1;
    else if (a == 5 || a == 6 || a == 0) cout << a;
    else cout << expo(a, b);
}