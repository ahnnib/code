#include <iostream>

#define int long long

signed main()
{
    int n;
    std::cin >> n;
    int a[n+1];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        if (a[i] == i || (a[a[i]] == i && i == a[a[i]])) ans++;
    }
    std::cout << ans;
}
/*
8
. .   . .   . .
1 2 4 4 5 7 7 8
8 7 7 5 4 4 2 1
  2 3       7
15
*/