#include <iostream>

int main()
{
    #define task "caesar"
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    int k; std::string s;
    std::cin >> k;
    std::cin.ignore();
    std::getline(std::cin, s);

    char caesar[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ') continue;
        else s[i] = caesar[int(s[i]) - 65 + k];
    }

    std::cout << s;
}