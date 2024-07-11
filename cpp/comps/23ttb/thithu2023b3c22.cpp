#include <iostream>
#include <math.h>
using namespace std;

#define int long long

signed main()
{
    int n;
    cin >> n;
    int a[n+1];
    int d[n+1]; d[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i],
        d[i] = d[i-1] + a[i];

    int l = 1, r = n, mid;
    while (l < r)
    {
        if (2 * (d[r] - d[l-1]) >= d[n]) r--;
        else l++;
    }
    cout << l << ' ' << r;
}
/*
5
1 2 3 4 5
1 3 6 10 15

abs(sum - (d[n] - sum))
abs(sum - d[n] + sum)
abs(2sum - d[n]) -> min
abs(2([r] - d[l-1]) - d[n]) min

*/