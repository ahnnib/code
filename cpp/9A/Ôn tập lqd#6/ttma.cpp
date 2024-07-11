#include <iostream>
#include <algorithm>

char ss(std::string a, std::string b)
{
    int sa = a.size(),
        sb = b.size();

    if (sa < sb) return '<';
    if (sa > sb) return '>';
    for (int i = 0; i < sa; i++)
    {
        if (a[i] < b[i]) return '<';
        if (a[i] > b[i]) return '>';
    }

    return '=';
}

bool cmp(std::pair<std::string, int> &a, std::pair<std::string, int> &b)
{
    char ch = ss(a.first, b.first);

    if (ch == '<') return 1;
    if (ch == '>') return 0;
    if (ch == '=')
        return a.second < b.second;
}

int main()
{
    freopen("ttma.inp", "r", stdin);
    freopen("ttma.out", "w", stdout);

    int n;
    std::cin >> n;
    std::pair<std::string, int> a[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i].first,
        a[i].second = i;

    std::sort(a, a + n, cmp);

    for (int i = 0; i < n; i++)
        std::cout << a[i].second+1 << '\n';
}