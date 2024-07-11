#include <iostream>

char makeerr(char ch)
{
    if ('a' <= ch && ch <= 'z') return ch - 32;
    else return ch;
}

int main()
{
    freopen("makeerr.inp", "r", stdin);
    freopen("makeerr.out", "w", stdout);

    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin.ignore();
    std::getline(std::cin, s);

    while (k --> 0)
    {
        int p;
        std::cin >> p;
        s[p-1] = makeerr(s[p-1]);
    }

    std::cout << s;
}