#include <iostream>
#include <vector>

#define int short
#define debug std::cout << "dfad\n";

std::vector<int> chebai(std::vector<int> v)
{
    std::vector<int> res;

    for (int i = 0; i < 54; i++)
        res.push_back(v[i]),
        res.push_back(v[i+54]);

    return res;
}

std::vector<int> cupbai(std::vector<int> v, int x)
{
    std::vector<int> res;

    for (int i = 108 - x; i < 108; i++)
        res.push_back(v[i]);
    for (int i = 0; i < 108 - x; i++)
        res.push_back(v[i]);

    return res;
}

signed main()
{
    #define task "uno"
    #ifndef ONLINE_JUDGE
    #else
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    #endif

    std::vector<int> cards(108);
    for (int i = 0; i < 108; i++)
        cards[i] = i+1;

    int n;
    std::cin >> n;
    while (n--)
    {
        int x;
        std::cin >> x;

        if (x == 0) cards = chebai(cards);
        else cards = cupbai(cards, x);
    }

    for (int i : cards) std::cout << i << ' ';
}
