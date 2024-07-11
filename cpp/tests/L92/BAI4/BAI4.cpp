#include <iostream>

#define debug std::cout << "dfad\n";

bool nguyenam(char c)
{
    return (c == 'a' ||
            c == 'e' ||
            c == 'i' ||
            c == 'o' ||
            c == 'u');
}

int main ()
{
    freopen("BAI4.INP", "r", stdin);
    freopen("BAI4.OUT", "w", stdout);

    int n; std::string s;
    std::cin >> n >> s;

    int i = 0;
    int cnt = 0, ans = 0;

    while (i < n)
    {
        while (nguyenam(s[i]) && i < n)
            cnt++,
            i++;
        // std::cout << i << '\n';
        if (cnt == 0) i++;
        ans = std::max(ans, cnt);
        cnt = 0;
    }

    std::cout << (ans ? ans : -1);
}

/*
11
ioiabcsmart

4
*/