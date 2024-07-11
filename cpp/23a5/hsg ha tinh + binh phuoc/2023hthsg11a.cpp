#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n; long long k;
    cin >> n >> k;
    int a[n+1]; long long s[n+1] = {};
    for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i-1] + a[i];

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = i, r = n, mid;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (s[mid] - s[i-1] <= k) l = mid + 1;
            else r = mid - 1;
        }

        if (s[r] - s[i-1] == k) ans++;
    }

    cout << ans;
}
/*
5 8
1 1 3 5 8
1 2 5 10 18
*/