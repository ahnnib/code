// n <= 1e18
#include <iostream>
using namespace std;

const long long mod = 1e9 + 7;

int main()
{
    long long n;
    cin >> n;
    long long k = n / 2;
    // cout << (k % mod * (k - 1 + (n % 2)) % mod) % mod;
    // k += mod;
    k %= mod;
    long long kq = k * k % mod;

    if (n % 2 == 0)
    {
        kq -= k;
        kq += mod;
        cout << kq % mod;
    }
    else cout << kq;
}
/*
1 2 3 4 5

(n / 2, n / 2 + 1 -> n - 1)
*/