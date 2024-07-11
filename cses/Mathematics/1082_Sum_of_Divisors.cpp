#include <iostream>
// #include <math.h>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    long n;
    cin >> n;

    // int root = sqrt(n);
    long long sum = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            if (i != n / i) sum += n / i;
            sum %= mod;
        }
    }
    cout << sum;
}