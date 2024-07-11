#include <iostream>

const long long mod = 2004010501;

int main()
{
    #define task "squpro"
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    int n;
    std::cin >> n;
    int a[n];
    int cntchan = 0, cntle = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        a[i] %= 2;
        cntle += a[i] % 2;
    } cntchan = n - cntle;

    for ()
    long long ans = 0;
}