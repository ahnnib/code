#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    freopen("unreal.inp", "r", stdin);
    freopen("unreal.out", "w", stdout);

    int n, k;
    std::cin >> n >> k;
    int a[n+1]; long long d[n+1] = {};
    for (int i = 1; i <= n; i++)
        std::cin >> a[i],
        d[i] = d[i-1] + a[i];

    int q;
    std::cin >> q;
    while (q--)
    {
        long long X;
        std::cin >> X;

        long long maxsum = 0;
        int l = 0, r = 0;
        for (int i = 1; i <= n-k+1; i++)
        {
            int j = i+k-1;
            long long sum = d[j] - d[i-1];
            if (maxsum < sum && sum <= X)
                maxsum = sum,
                l = i, r = j;
        }

        std::cout << l << ' ' << r << '\n';
    }

}