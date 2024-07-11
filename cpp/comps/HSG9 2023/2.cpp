#include <bits/stdc++.h>

int main()
{
    std::string s;
    std::getline(std::cin, s);

    int d[(int)1e6+1] = {};
    for (char i : s) d[i]++;

    int ans = 0;
    for (int i = 0; i <= 1e6; i++)
        if (d[i] >= 2) ans++;

    std::cout << ans;
}