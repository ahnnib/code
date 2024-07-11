#include <iostream>

int main()
{
    std::string s;
    std::cin >> s;

    int ans = 0, cnt = 1;
    for (int i = 0; i < s.size(); i++)
    {
        while (s[i] == s[i+1]) i++, cnt++;
        ans = std::max(ans, cnt); cnt = 1;
    }

    std::cout << ans;
}