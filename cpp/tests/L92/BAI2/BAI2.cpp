#include <iostream>

int main ()
{
    freopen("BAI2.INP", "r", stdin);
    freopen("BAI2.OUT", "w", stdout);

    int n;
    std::cin >> n;

    long a[n];
    std::cin >> a[0] >> a[1];
    long max3 = 0;
    int r;
    for (int i = 2; i < n; i++)
    {
        std::cin >> a[i];
        if (a[i] - a[i-2] > max3)
            max3 = a[i] - a[i-2],
            r = i;
    }

    std::cout << a[r] - a[r-2];



}

/*
4
2 4 5 6


*/