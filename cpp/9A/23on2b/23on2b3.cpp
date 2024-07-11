#include <iostream>

int main()
{
    int q;
    std::cin >> q;
    while (q --> 0)
    {
        int a, l, r;
        std::cin >> a >> l >> r;

        int ans = 0;
        for (int x = l; x <= r; x++)
        {
            if ((x | a) == x) ans++;
        }
        std::cout << ans;
    }
}
/*
x = 1
001

010 2
011 3
100 4
101 5
110

8 4 2 1
0 0 0 0
*/