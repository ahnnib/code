#include <iostream>
using namespace std;

#define debug cout << "dfad\n";

bool prime(long long n)
{
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (long long i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    return 1;
}

const int MAX = 2e7 + 1;
long long UQ[MAX];

long long uq(int n)
{
    // if (n < MAX) return UQ[n];
    if (n == 1 || prime(n)) return n;
    if (n < MAX && UQ[n] != 0) return UQ[n];
    long long res = 1;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            res += uq(i) + (i != n / i ? uq(n/i) : 0);

    if (n < MAX) UQ[n] = res;
    return res;
}
int main()
{
    // for (int i = 1; i < MAX; i++) UQ[i] = i;
    // for (int i = 2; i * i < MAX; i++)
    // {
    //     if (UQ[i] == i)
    //         for (int j = i * i; j < MAX; j += i)
    //             UQ[j] = 0;
    // }
    // for (int i = 4  ; i < MAX; i++)
    // {
    //     if (UQ[i] == 0)
    //     {
    //         UQ[i] = 1;
    //         for (int j = 2; j * j <= i; j++)
    //         {
    //             if (i % j == 0) UQ[i] += UQ[j] + (j == i/j ? 0 : UQ[i/j]);
    //         }
    //         // UQ[i] = res;
    //     }
    // }

    // for (int i = 0; i <= 100; i++) cout << UQ[i]<<" ";
    // cout <<"\n";
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int n;
    while (cin >> n)
    {
        if (n == 0) return 0;

        cout << uq(n) << '\n';
    }
}