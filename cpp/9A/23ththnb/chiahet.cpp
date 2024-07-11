#include <iostream>
#include <math.h>

#define int long long
#define pow(a, b) round(pow(a, b))

signed main()
{
    #define task "chiahet"
    #ifndef ONLINE_JUDGE
    #else
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    #endif

    int n, k;
    std::cin >> n >> k;

    int d2 = 0, d5 = 0;
    while (n % 2 == 0)
        n /= 2,
        d2++;
    while (n % 5 == 0)
        n /= 5,
        d5++;

    if (d2 <= k) d2 = k - d2;
    else d2 = 0;
    if (d5 <= k) d5 = k - d5;
    else d5 = 0;

    std::cout << pow(2, d2) * pow(5, d5) << '\n';
}