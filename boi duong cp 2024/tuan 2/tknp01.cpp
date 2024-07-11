#include <iostream>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < k; i++) {
        int x; cin >> x;


        int l = 0, r = n-1, mid;
        while (l <= r) {
            // cout << l << ' ' << r << ' ' << mid << '\n';
            mid = (l + r) >> 1;
            if (a[mid] < x) l = mid + 1;
            else r = mid - 1;
        }
        if (a[l] == x) cout << "YES\n";
        else cout << "NO\n";
    }
}
/*
10 10
1 61 126 217 2876 6127 39162 98126 712687 1000000000
100 6127 1 61 200 -10000 1 217 10000 1000000000

*/