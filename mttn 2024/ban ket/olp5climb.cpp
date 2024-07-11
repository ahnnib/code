#include <iostream>
using namespace std;

#define int long long

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int n, q; cin >> n >> q; int a[n+1], b[n+1], s[n+1] = {};
    for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i-1] + a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    while (q--) {
        int k; cin >> k;

        int i = 1;
        while (i <= n) {
            if (k >= a[i]) k -= b[i];
            else break;
            i++;
        } i--;

        cout << s[i] << '\n';
    }
}
/*
3 4
2 3 5
2 -1 1

0 2 5 10
0 2 1 2

k - sb[i] >= a[i]

1 2 5 8
*/