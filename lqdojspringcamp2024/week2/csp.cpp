#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    int i = 0, j = n-1; long long cnt = 0;
    while (i < j) {
        while (j > i && a[i] + a[j] > m) j--;
        if (a[i] + a[j] <= m) cnt += j - i;
        i++;
    }

    cout << cnt;
}
