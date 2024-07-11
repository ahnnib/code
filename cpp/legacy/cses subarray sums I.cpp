// cses subarray sums I

#include <iostream>

#define debug std::cout << "dfad\n";
#define int long long

signed main() {
    int n, x;
    std::cin >> n >> x;
    int a[n+1]; a[0] = 0;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i],
        a[i] += a[i-1];

    // for (int i = 1; i <= n; i++)
    //     std::cout << a[i] << ' ';
    // std::cout << '\n';


    int i = 1, j = 1, ans = 0;
    while (j <= n) {
        while (a[i] - a[j-1] < x && i <= n)
            i++;
        // std::cout << i << ' ' << j << ' ' << '\n';
        if (a[i] - a[j-1] == x) ans++;

        j++;
    }
    std::cout << ans;
}

/*
2 4 1 2 7
        i
2 6 7 9 16
        j

2
*/