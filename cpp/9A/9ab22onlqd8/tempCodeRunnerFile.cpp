#include <iostream>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    int b[n], c[n];
    for (int i = 0; i < n; i++) std::cin >> b[i];
    for (int i = 0; i < n; i++) std::cin >> c[i];

    std::sort(b, b + n); std::sort(c, c + n);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int l = 0, r = n-1, mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (b[i] + c[mid] < 0) l = mid + 1;
            else r = mid - 1;
        }
        ans = std::min(ans, b[i] + c[mid]);
    }
    std::cout << ans;
}