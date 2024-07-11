#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    if (1 < n && n < 4) return std::cout << "NO SOLUTION", 0;
    for (int i = n-1; i >= 1; ----i) std::cout << i << ' ';
    for (int i = n; i >= 1; ----i) std::cout << i << ' ';

}
/*
1
1
2
NO
3
NO
4
NO
5
5 3 1 4 2
*/