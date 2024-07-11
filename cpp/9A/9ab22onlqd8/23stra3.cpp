#include <iostream>

int main()
{
    freopen("baide.inp", "r", stdin);
    freopen("baide.out", "w", stdout);

    std::string s;
    std::cin >> s;

    int cntA = 0, cntB = 0, cntC = 0;
    for (char i : s)
    {
        cntA += i == 'A';
        cntB += i == 'B';
        cntC += i == 'C';
    }

    if (cntA == cntB || cntB == cntC || cntC == cntA) std::cout << "YES";
    else std::cout << "NO";
}