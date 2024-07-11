#include <iostream>
#include <math.h>

#define pow(a, b) round(pow(a, b))

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t;
    std::cin >> t;
    while (t --\
                \
                 \
                  \
                   \
                    \
                     \
                      >0)
    {
        int n; std::string s;
        std::cin >> n >> s;

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum = (sum + (s[i]-48) * (int) pow(2, n-i-1)) % 15;

        std::cout << (sum % 15 == 0) << '\n';
    }
}
/*
11110
2 + 4 + 8 + 16
24 + 2 + 4
30
*/