#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a, a + n); sort(b, b + m);

    int l = 0, r = 0, ans = 0;
    while (l < n && r < m)
    {
        if (abs(a[l] - b[r]) <= k) ans++, l++, r++;
        else if (a[l] - b[r] > k) r++;
        else l++;
    }

    cout << ans;
}
