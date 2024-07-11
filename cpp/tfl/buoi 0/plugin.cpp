#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n, greater<int>());

    if (m == 1) return cout << 0, 0;

    m -= 1; // ổ cắm đầu
    // - 1 + a[i+1]
    int sum = a[0], i = 1;
    for (; i < n && sum < m; i++) {
       sum = sum - 1 + a[i];
    }
    cout << (i < n ? i+1 : -1);
}