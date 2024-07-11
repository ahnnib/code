#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    int ans = 2147483647;
    for (int i = m-1; i < n; i++)
    {
        ans = min(ans, a[i] - a[i-m+1]);
    }

    cout << ans;
}