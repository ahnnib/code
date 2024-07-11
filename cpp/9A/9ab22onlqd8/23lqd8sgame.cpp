#include <iostream>
#include <algorithm>

void sub1(int n, int b[], int c[])
{
    int res = 217483647;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res = std::min(res, abs(b[i] + c[j]));

    std::cout << res;
}

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("sgame.inp", "r", stdin);
    freopen("sgame.out", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    int b[n], c[n];
    for (int i = 0; i < n; i++) std::cin >> b[i];
    for (int i = 0; i < n; i++) std::cin >> c[i];

    std::sort(b, b + n); std::sort(c, c + n);

    if (n <= 1000) sub1(n, b, c);
    else{
    int ans = 2147483647;
    for (int i = 0; i < n; i++)
    {
        int x = -b[i];
        int l = 0, r = n-1, mid, pos = n;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (c[mid] >= x)
                pos = mid, r = mid - 1;
            else l = mid + 1;
        }
        if (c[pos] == x) return std::cout << 0, 0;
        if (pos != -1) ans = std::min(ans, abs(b[i] + c[pos]));
        if (pos > 0) ans = std::min(ans, abs(b[i] + c[pos-1]));
    }
    std::cout << ans;
    }
}