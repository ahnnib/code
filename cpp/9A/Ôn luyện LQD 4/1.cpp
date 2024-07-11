#include <iostream>

int main()
{
    int n, m; std::string s;
    std::cin >> n >> m >> s;

    char f[123];
    for (char i = 'a'; i <= 'z'; i++)

        f[i] = i;

    while (m--)
    {
        char u, v;
        std::cin >> u >> v;

        char u1, v1;
        for (char i = 'a'; i <= 'z'; i++)
        {
            if (f[i] == u) u1 = i;
            if (f[i] == v) v1 = i;
        }
        std::swap(f[u1], f[v1]);
    }

    for (int i = 0; i < n; i++)
        std::cout << f[s[i]];
}
