#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int n; cin >> n;
    long long s[n+1] = {};
    int a[n+1]; for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n); for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];

    int q; cin >> q; while (q--) {
        long long k; cin >> k;

        int l = 1, r = n, mid, res = 0;
        while (l <= r) { // cuoi cung <
            mid = (l + r) >> 1;
            if (s[mid] < k * mid) res = mid, l = mid + 1;
            else r = mid - 1;
        }

        cout << res << '\n';
    }
}