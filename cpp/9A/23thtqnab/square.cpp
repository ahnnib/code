#include <iostream>
#include <math.h>

int main()
{
    #define task "square"
    #ifndef ONLINE_JUDGE
    #else
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    #endif

    int n, k;
    std::cin >> n >> k;

    int l = ceil(sqrt(k)), r = floor(sqrt(n));
    std::cout << r - l + 1;
}