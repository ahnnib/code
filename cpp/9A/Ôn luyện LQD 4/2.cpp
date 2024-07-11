#include <iostream>
#include <deque>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int n, m, q;
    std::cin >> n >> m >> q;
    int a[n], b[m];
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < m; i++) std::cin >> b[i];

    std:: deque<int> deque;
    for (int i = 0; i < n; i++)
        deque.push_back(a[i]);
    for (int i = m-1; i >= 0; i--)
        deque.push_back(b[i]);
    // for (auto i : deque) std::cout << i << ' ';

    while (q--)
    {
        int z, x;
        std::cin >> z >> x;

        if (z == 1)
        {
            std::cout << deque.back() << '\n';
            deque.push_front(x);
            deque.pop_back();
        }
        if (z == 2)
        {
            std::cout << deque.front() << '\n';
            deque.push_back(x);
            deque.pop_front();
        }
    }
}
/*
4 5 3
1 3 7 2
4 7 5 1 5
1 3
1 4
2 5
*/
