#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n+1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + n + 1);

    long long sum = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += a[i] * (i-1) - sum;
        sum += a[i];
        // cout << ans << ' ';
    }

    cout << ans;
}
/*
3
5 1 2
1 2 5


*/
