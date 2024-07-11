#include <iostream>
#include <vector>

#define int short

std::vector<int> cupbai(std::vector<int> x, int n)
{
    std::vector<int> a = (x.begin(), x.begin()+108-n);
    std::vector<int> b = (x.begin()+109-n, x.end());

    a.insert(a.end(), b.begin(), b.end());

    return a;
}

signed main()
{
    #define task "subarray"
    #ifndef ONLINE_JUDGE
    #else
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    #endif

    std::vector<int> cards(108);
    for (int i = 0; i < 107; i++) cards[i] = i;
    // int n;
    // std::cin >> n;
    // while (n--)
    // {

    // }

    int x;
    std::cin >> x;
    // if (x == 0) cards = chebai(cards);
     cards = cupbai(cards, x);

    for (int i : cards) std::cout << i << ' ';
}
